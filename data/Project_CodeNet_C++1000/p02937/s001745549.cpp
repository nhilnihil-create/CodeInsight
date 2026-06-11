#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s,t;cin>>s>>t;
  string ss=s+s;
  ll aa=ss.length(),b=t.length(),pos=-1,num=0;
  bool isok=true;
  map<char,lvector> mp;
  rep(i,aa) mp[ss[i]].emplace_back(i);
  rep(i,b) {
    pos++;
    auto itr=lower_bound(ALL(mp[t[i]]),pos);
    if(itr==mp[t[i]].end()) {
      pos=0;num++;
      itr=lower_bound(ALL(mp[t[i]]),pos);
      if(itr==mp[t[i]].end()) isok=false;      
    }
    if(!isok) break;
    pos=*itr;
  }
  print(isok?aa*num+pos+1:-1);
  return 0;
}
