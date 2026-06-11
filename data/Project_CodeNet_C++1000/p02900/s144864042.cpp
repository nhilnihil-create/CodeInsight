#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

vector<long long> enum_divisors(long long N){
    vector<long long> res;
    for(long long i=1;i*i<=N;i++){
        if(N%i==0){
            res.push_back(i);
            if(N/i!=i) res.push_back(N/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

int main(){
	ll a,b;
	cin >> a >> b;
	ll n=__gcd(a,b);
	auto res=enum_divisors(n);
	ll count=0;
	for(auto p:res){
		if(is_prime(p)) count++;
	}
	cout << count+1 << endl;
}
