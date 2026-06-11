#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll N;
  cin>>N;
  vector<ll> v(N);
  for(ll i = 0; i < N; i++) cin>>v[i];
  sort(v.begin(),v.end());
  if(v[N-1]>0&&v[0]<0){
    ll ans = 0;
    for(auto x:v) ans+=abs(x);
    cout<<ans<<endl;
    ll t = v[N-1];
    ll i = 0;
    while(v[i+1]<=0){
      cout<<t<<" "<<v[i]<<endl;
      t-=v[i];
      i++;
    }
    ll j = N-2;
    ll s = v[i];
    while(v[j]>0){
      cout<<s<<" "<<v[j]<<endl;
      s-=v[j];
      j--;
    }
    cout<<t<<" "<<s<<endl;
  }
  if(v[0]>=0){
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
      if(i==0) ans-=v[i];
      else ans+=v[i];
    }
    cout<<ans<<endl;
    ll t = v[0];
    for(ll i = 1; i < N-1; i++){
      cout<<t<<" "<<v[i]<<endl;
      t-=v[i];
    }
    cout<<v[N-1]<<" "<<t<<endl;
  }
  else if(v[N-1]<=0){
    ll ans = 0LL;
    for(ll i = 0; i < N; i++){
      if(i==N-1) ans-=v[i];
      else ans+=v[i];
    }
    cout<<abs(ans)<<endl;
    ll t = v[N-1];
    for(int i = 0; i < N-1; i++){
      cout<<t<<" "<<v[i]<<endl;
      t-=v[i];
    }
  }
}