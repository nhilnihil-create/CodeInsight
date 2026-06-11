#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  int n;
  cin>>n;
  vector<string> s(n);
  rep(i,n) cin>>s[i];
  map<string,int> mp;
  rep(i,n){
    mp[s[i]]++;
  }
  int mx=0;
  for(auto x:mp) mx=max(mx,x.second);
  for(auto x:mp){
    if(x.second==mx) cout<<x.first<<endl;
  }
}