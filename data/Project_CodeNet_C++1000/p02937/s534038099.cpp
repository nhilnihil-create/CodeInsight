#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

#define int ll

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s,t;
  cin>>s>>t;
  map<char,int>m;
  vector<map<char,int>>ms(s.size()+1);
  bool ok=true;
  ms[s.size()-1][s[s.size()-1]]=1;
  for(int i=s.size()-1;i>0;i--){
    for(auto it:ms[i])ms[i-1][it.first]=++it.second;
    ms[i-1][s[i-1]]=1;
  }
  for(auto it:t)if(ms[0][it]==0)ok=false;
  if(!ok){
    cout<<-1<<endl;
    return 0;
  }
  m=ms[0];
  int ans=0;
  int now=0;
  for(auto it:t){
    if(m[it]>0){
      now+=m[it];
      m=ms[now];
    }
    else{
      ans++;
      now=0;
      now+=ms[now][it];
      m=ms[now];
    }
  }

  cout<<ans*s.size()+now<<endl;
  return 0;
}
