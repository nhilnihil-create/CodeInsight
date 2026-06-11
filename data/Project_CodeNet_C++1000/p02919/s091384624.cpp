#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
multiset<ll> ms,ms_;
int main(){
  ll n;
  cin>>n;
  vector<P> vec;
  for(int i=1;i<=n;i++){
    ll a;
    cin>>a;
    vec.push_back(P(a,i));
  }
  sort(vec.begin(),vec.end(),greater<P>());
  ms.insert(0);
  ms.insert(0);
  ms.insert(n+1);
  ms.insert(n+1);
  ms_.insert(0);
  ms_.insert(0);
  ms_.insert(-(n+1));
  ms_.insert(-(n+1));
  ll ans=0;
  for(int i=0;i<n;i++){
    auto itr=ms.upper_bound(vec[i].second);
    ll y=*itr;
    itr++;
    ll z=*itr;

    auto itr2=ms_.upper_bound(-vec[i].second);
    ll x=*itr2;
    x*=-1;
    itr2++;
    ll w=*itr2;
    w*=-1;
    ll pos=vec[i].second;
    ans+=vec[i].first*((x-w)*(y-pos)+(z-y)*(pos-x));

    ms.insert(pos);
    ms_.insert(-pos);
  }
  cout<<ans<<endl;
}
