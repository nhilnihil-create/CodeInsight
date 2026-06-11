#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int n;
  cin>>n;
  vector<P> p(n);
  rep(i,n){
    ll x, l;
    cin >> x >> l;
    p[i] = make_pair(x-l,x+l);
  }
  sort(p.begin(),p.end());
  int ans=n;
  ll right=p[0].second;
  for(int i=1; i < n; i++){
    if(right <= p[i].first) right=p[i].second;
    else if(p[i].second < right){
      right=p[i].second;
      ans--;
    }else ans--;
  }
  cout<<ans<<endl;
}
