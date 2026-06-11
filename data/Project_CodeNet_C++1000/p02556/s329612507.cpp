#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const ll MOD = 1e9+7;
const int INF = 1001001001;
// const ll INF = 1000000000000000000LL;

 int main() {
     int n;
     cin >> n;
     vector<ll> x(n);
     vector<ll> y(n);
     rep(i,n) cin >> x[i] >> y[i];
     vector<ll> mx(n);
     vector<ll> my(n);
     rep(i,n) mx[i] = x[i]-y[i];
     rep(i,n) my[i] = x[i]+y[i];
     sort(mx.begin(),mx.end());
     sort(my.begin(),my.end());
     ll ans = max(mx.back()-mx[0],my.back()-my[0]);

     cout << ans << endl;
     return 0;
 }