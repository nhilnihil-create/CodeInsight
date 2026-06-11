#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const ll INF = 1e17;
const int MOD = 1000000007;

 
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);
  rep(i,n-1) a.at(i+1) += a.at(i);
  
  ll ans = INF;
  rep(i,n-1){
    ans = min(ans,abs(a.at(n-1) - 2*a.at(i)));
  }
  
  cout << ans << endl;            
  return 0;
}




