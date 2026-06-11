#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename T>
void print_vec(const vector<T>& v, bool is_reverse=false, int num=0){
  if(num == 0) num = (int)v.size();
  if(is_reverse) for(int i=num-1; i>=0; i--){ cout<<v[i]; if(i!=0) cout<<" ";}
  else for(int i=0; i<num; i++){ cout<<v[i]; if(i!=num-1) cout<<" ";}
  cout << endl;
}

template <typename T>
void print_pairvec(const vector<T> &v, int num=0){
  if(num == 0) num = (int)v.size();
  cout << endl;
  for(int i=0; i<num; i++){ cout << v[i].first << " " << v[i].second << endl;}
}


template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}

struct Eratosthenes{
	vector<ll> sieve;// sieve[i]: 数字iがエラトスとネスで篩落とされた時の素数

	Eratosthenes(ll n): sieve(n+1){
		for(int i=0; i<=n; i++) sieve[i] = i;
		for(ll i=2; i*i<=n; i++){
			if(sieve[i] < i) continue;//すでに篩落とされているならcontinue
			for(int j=i*i; j<=n; j+=i) sieve[j] = min(sieve[j], i);
		}
	}

	vector<ll> prime_divisors(ll x, bool tmp=false){
		vector<ll> res(1, 1); //back()のところで ひっかかるので1を入れておく
		while(x > 1){
			if(res.back() != sieve[x]) res.push_back(sieve[x]);
			x /= sieve[x];
		}
		return res;
	}

	map<ll, int> prime_divisors(ll x, int tmp=0){
		map<ll, int> mp;
		while(x > 1){
			mp[sieve[x]]++;
			x /= sieve[x];
		}
		return mp;
	}
};

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
int main(){
	int N;
	cin >> N;
	vector<ll> A(N);
	for(int i=0; i<N; i++) cin >> A[i];
	
	ll g = A[0];
	for(int i=1; i<N; i++) g = gcd(g, A[i]);
	if(g != 1){
		cout << "not coprime" << endl;
		return 0;
	}

	const int INF = 1e6;
	Eratosthenes era(INF);
	map<ll, int> mp;
	for(int i=0; i<N; i++){
		vector<ll> vec = era.prime_divisors(A[i], false);
		for(ll prime : vec){
			if(prime == 1) continue;
			if(mp[prime] != 0){
				cout << "setwise coprime" << endl;
				return 0;
			}
			mp[prime]++;
		}
	}
	cout << "pairwise coprime" << endl;
	return 0;
}

