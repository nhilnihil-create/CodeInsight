#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(long long i=0;i<int(N);++i)
using ll = long long;
// const int INF = 2147483647;
const ll MOD = 1e9+7;
const ll INF = 1000000000000000000LL;
 
 
 int main() {
	 ll k,n;
	 cin >> k >> n;
	 vector<ll> a(n);
	 rep(i,n) cin >> a[i];
	 ll nax = -INF;
	 rep(i,n-1){
		 ll cur = a[i+1]-a[i];
		 nax = max(nax,cur);
	 }
	 nax = max(nax, a[0]+k-a[n-1]);
	 cout << k - nax << endl;
	 return 0;
 }
