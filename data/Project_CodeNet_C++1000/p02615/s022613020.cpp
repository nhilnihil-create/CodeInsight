#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(long long i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1e9+7;
// const ll INF = 1000000000000000000LL;
 
 
 int main() {
	 int n;
	 cin >> n;
	 vector<int> a(n);
	 rep(i,n) cin >> a[i];
	 priority_queue<int> v;
	 sort(a.begin(),a.end(),greater<int>());
	 v.push(a[0]);
	 ll ans = 0;
	 for(int i=1;i<n;i++){
		 ans += v.top();
		 v.pop();
		 int cur = a[i];
		 for(int j=0;j<2;j++){
			 v.push(cur);
		 }
	 }
	 cout << ans << endl;
	 return 0;
 }
