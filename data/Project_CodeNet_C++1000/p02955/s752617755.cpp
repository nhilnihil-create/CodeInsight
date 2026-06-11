#include <bits/stdc++.h>
using namespace std;
typedef long long ll;





class Primes {
public:
	int size;
	vector<int> v, primes;
	Primes(int _size) : size(_size), v(_size,0), primes(){
		int sqrtsize = (int)sqrt((double)_size);
		
		for ( int i = 2; i < size; i++ ){
			if ( v[i] )
				continue;
			primes.push_back(i);
			if ( i <= sqrtsize )
				for ( int j = i*i; j < _size; j+=i )
					v[j] = 1;
		}
	}
	
	// map<prime,pow>
	map<int,int> factor(ll x){
		map<int,int> m;
		for ( auto it : primes ){
			int prime = it;
			if ( x < prime )
				break;
			
			int count = 0;
			while ( x % prime == 0 ){
				x /= prime;
				count++;
			}
			if ( count )
				m[prime] = count;
		}
		if ( x != 1 )
			m[x] = 1;
		return m;
	}
	
	
	vector<pair<int,int>> factorv(ll x){
		auto m = factor( x );
		vector<pair<int,int>> v;
		for ( auto it : m ){
			v.push_back({it.first,it.second});
		}
		return v;
	}
	
	// 約数を求める
	vector<int> divisor( ll x ){
		auto v = factorv( x );
		vector<int> div;
		divisor2( div, v, 0, 1 );
		sort(div.begin(), div.end());
		return div;
	}
	
	int divisor2( vector<int> &div, vector<pair<int,int>> &v, size_t i, int mul ){
		for ( int j = 0; j <= v[i].second; j++ ){
			if ( i == v.size()-1 ){
				div.push_back(mul);
			}
			else {
				divisor2( div, v, i+1, mul );
			}
			mul *= v[i].first;
		}
	}
	
	
};


ll N, K;

int main(){
	cin >> N >> K;
	
	vector<ll> A(N);
	ll Asum = 0;
	for ( int i = 0; i < N; i++ ){
		cin >> A[i];
		Asum += A[i];
	}
	
	Primes p(50*1000);
	
	// 回答は、A の合計の約数になっているはず
	auto d = p.divisor(Asum);
	sort(d.begin(),d.end(),greater<int>());
	
	
	for ( auto result : d ){
		vector<ll> diff(N);
		
		// K回以下の操作でできるか調べる
		// A を result で割って、余りをソート
		for ( int i = 0; i < N; i++ ){
			diff[i] = A[i] % result;
		}
		sort( diff.begin(), diff.end() );
		
		//cout << result << endl;
		//for ( int j = 0; j < N; j++ )
		//	cout << "diff: " << diff[j] << endl;
		
		vector<ll> acc(N+1);
		ll diffsum = 0;
		for ( int i = 0; i < N; i++ ){
			acc[i] = diffsum;
			diffsum += diff[i];
		}
		acc[N] = diffsum;
		
		// diff[0..i-1] <- -1 
		// diff[i..N-1] <- +1 
		for ( int i = 1; i < N; i++ ){
			if ( acc[i] <= K && (N-i)*result - (acc[N]-acc[i]) <= K ){
				
				cout << result << endl;
				return 0;
			}
		}
	}
	
	return 0;
}

