#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int inf=1000000007;


int main(){
  int n;
  cin >> n;
  vector<int> val(n+10,0);
  ll ans=0;

  rep(i,1,n+1){
    ll a;
    cin >> a;
    if(a+i<=n) val[a+i]++;
    if(i-a>0) ans +=val[i-a];
//    cout << i+a << ' ' << val[i-a] << endl;
  }
  cout << ans << endl;
  return 0;
}