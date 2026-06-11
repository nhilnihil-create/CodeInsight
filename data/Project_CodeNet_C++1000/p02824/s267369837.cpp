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
  ll N,M,V,P;
  cin>>N>>M>>V>>P;
  vector<ll> v(N);
  for(ll i = 0; i < N; i++) cin>>v[i];
  sort(v.begin(),v.end());
  ll r = N,l=-1;
  while(r-l>1){
    bool ok = false;
    ll mid = (r+l)/2;
    if(v[mid]>=v[N-P]) ok = true;
    else if(mid+P>=V&&v[mid]+M>=v[N-P]) ok=true;
    else{
      ll rest = (V-(P+mid))*M;
      ll n = 0LL;
      for(ll i = mid+1;i<=N-P;i++) n+=(v[mid]+M-v[i]);
      if(n>=rest) ok=true;
    }
    if(v[mid]+M<v[N-P]) ok=false;
    if(ok) r=mid;
    if(!ok) l=mid;
  }
  cout<<N-r<<endl;
}