#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

ll gcd(ll a, ll b){
	if(b==0) return a;
	
	return gcd(b, a%b);
}

vector<pair<ll, ll>> prime_factorize(ll n){
	vector<pair<ll, ll>> prime;
	
	for(ll i=2; i*i<=n; ++i){
		if(n%i!=0) continue;
		pair<ll,ll> p = make_pair(i,0);
		while(n%i==0){
			p.second++;
			n /= i;
		}
		prime.push_back(p);
	}
	
	if(n != 1) prime.push_back(make_pair(n,1));
	
	return prime;
}

int main(){
	ll a,b;
	cin >> a >> b;
	
	ll d = gcd(a,b);
	
	vector<pair<ll,ll>> prime = prime_factorize(d);
	
	bool primehas1 = false;
	for(auto x: prime){
		if(x.first==1) primehas1=true;
	}
	if(!primehas1) prime.push_back(make_pair(1,1));
	
	cout << prime.size() << endl;
	
	return 0;
}