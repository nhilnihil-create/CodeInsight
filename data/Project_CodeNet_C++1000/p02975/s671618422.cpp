#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  bool f=1;
  rep(i,n){
    if(a[i]!=0) f=0; 
  }
  if(f){
    cout << "Yes" << endl;
    return 0;
  }
  if(n%3!=0){
    cout << "No" << endl;
    return 0;
  }
  map<ll,int> mp;
  rep(i,n){
    mp[a[i]]++;
  }
  if(mp.size()==3){
    bool f=1;
    vector<ll> v(0);
    for(auto c:mp){
      v.push_back(c.first);
      if(c.second!=n/3) f=0;
    }
    if((v[0]^v[1]^v[2])!=0) f=0;
    if(f){
      cout << "Yes" << endl;
      return 0;
    }
  }
  if(mp.size()==2){
    bool f=0,f1=0,f2=0;
    for(auto c:mp){
      if(c.first!=0&&c.second==2*n/3) f1=1;
      if(c.first==0&&c.second==n/3) f2=1;
    }
    if(f1&&f2) f=1;
    if(f){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}