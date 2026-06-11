#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)//変更有
using ll = long long;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<int> v(n);
  ll sum=0;
  rep(i,n){
    cin >> v[i];
    sum+=v[i];
  }
  ll finalans=1;
  int zzz=sqrt(sum)+1;
  rep(i,zzz){
    if(i==0) continue;
    if(sum%i!=0) continue;
    ll x=sum/i;
    ll ans=0;
    ll ans2=0;
    vector<pair<int,int>> vec;
    for(int y:v){
      vec.push_back(make_pair(y%x,x-y%x));
    }
    sort(vec.begin(),vec.end());
    int a=-1,b=v.size();
    while(b-a!=1){
      a++;
      ans+=vec[a].first;
      while(ans>=ans2+vec[b-1].second){
        b--;
        ans2+=vec[b].second;
      }
    }
    
    if(ans<=k) finalans=max(finalans,x);
  }
  rep(i,zzz){
    if(i==0) continue;
    if(sum%i!=0) continue;
    ll x=i;
    ll ans=0;
    ll ans2=0;
    vector<pair<int,int>> vec;
    for(int y:v){
      vec.push_back(make_pair(y%x,x-y%x));
    }
    sort(vec.begin(),vec.end());
    int a=-1,b=v.size();
    while(b-a!=1){
      a++;
      ans+=vec[a].first;
      while(ans>=ans2+vec[b-1].second){
        b--;
        ans2+=vec[b].second;
      }
    }
    if(ans<=k) finalans=max(finalans,x);
  }
  cout << finalans << endl;
}