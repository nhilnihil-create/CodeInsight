
#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define LINF (ll)1e18
#define INF (int)1e9
#define ll_1e9 (ll)1e9
using namespace std;

int main(){
  ll s;
  cin >> s;
  
  ll y3 = (s-1) / ll_1e9 + 1,x3 = y3*ll_1e9 - s;
 
  cout << 0 << " " << 0 << " " << ll_1e9 << " " << 1 << " " << x3 << " " << y3 << endl;
  return 0;
}