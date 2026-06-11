#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const ll INF = (1LL << 31) - 1;
const double pi=acos(-1);

int main(){
  int n;
  cin >> n;
  map<ll,int>mp;
  rep(i,n){
    ll a;
    cin >> a;
    mp[a]++;
  }
  bool ok=false;
  if(mp[0]==n){
    ok=true;
  }
  else{
    ll sum=0;
    vector<ll>vec;
    for(auto p:mp){
      if(p.second){
        sum++;
        vec.push_back(p.first);
      }
    }
    
    if(n%3==0 && sum==2){
      if(mp[0]==n/3) ok = true;
    }
    if(n%3==0 && sum==3){
      bool can = true;
      for(auto t:mp){
      	if(t.second && t.second!=n/3) can = false;
      }
      ll bit=0;
      rep(i,3){
        bit^=vec[i];
      }
      if(can && !bit) ok = true;
    }
  }
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
