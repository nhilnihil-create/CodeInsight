#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  int d,a;
  cin>>n>>d>>a;
  vector<pair<int,int>> vec(n);
  vector<ll> s(n+1,0);
  for(int i=0;i<n;i++){
    ll x,h;
    cin>>x>>h;
    h=(h+a-1)/a;
    vec[i]=make_pair(x,h);
  }
  sort(vec.begin(),vec.end());
  ll ans=0;
  for(int i=0;i<n;i++){
    if(vec[i].second-s[i]<=0){
      s[i+1]+=s[i];
      continue;
    }
    int now=vec[i].first+d;
    int edge=now+d;
    int x;
    if(edge>=vec[n-1].first){
      x=n-1;
    }
    else{
      int ok=-1,ng=n-1;
      while(ng-ok!=1){
        int check=(ok+ng)/2;
        if(vec[check].first<=edge){
          ok=check;
        }
        else{
          ng=check;
        }
      }
      x=ok;
    }
    int y=vec[i].second-s[i];
    ans+=y;
    s[i]+=y;
    s[x+1]-=y;
    s[i+1]+=s[i];
  }
  cout<<ans<<endl;
}