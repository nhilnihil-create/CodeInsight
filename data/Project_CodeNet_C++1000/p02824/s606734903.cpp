#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
ll n,m,v,p;
vector<ll> a(n);

bool ok(int x){
  if(x >= n-p) return true;
  if(a[x] + m < a[n-p]) return false;
  ll res = 0;
  rep(i,n){
    if(i <= x) res += m;
    else if(i >= n-p+1) res += m;
    else{
      res += a[x]-a[i]+m;
    }
  }
  return res >= v*m;
}
 
int main() {
  cin >> n >> m >> v >> p;
  a.resize(n);
  rep(i,n) cin >> a.at(i);
  sort(a.begin(),a.end());
  int left = -1,right = n;
  while(right - left > 1){
    int mid = (left + right)/2;
    if(ok(mid)) right = mid;
    else left = mid;
  }
  
  cout << n-right << endl;
  
  return 0;
}


    