#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int inf=1000000007;


int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  ll mx=0;
  rep(i,0,n){
    cin >> a[i];
    mx = max(mx,a[i]);
  }
//  cout << mx << endl;
  vector<P> val(mx+1);
  sort(a.begin(), a.end());
  rep(i,0,n){
    val[a[i]].first++;
    for(int j=a[i];j<=mx+1;j+=a[i]){
      if(val[j].second==2) continue;
      val[j].second++;
    }
  }
  ll ans =0;
  rep(i,1,mx+1){
    if(val[i].first==1&&val[i].second==1){
      ans+=1;
//      cout << i << endl;
    }
  }
  cout << ans << endl;
  return 0;
}