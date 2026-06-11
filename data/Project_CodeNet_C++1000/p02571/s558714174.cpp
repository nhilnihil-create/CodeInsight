#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=Int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s,t;
  cin>>s>>t;
  Int n=s.size(),m=t.size();
  Int ans=n;
  for(Int i=0;i+m<=n;i++){
    Int res=0;
    for(Int j=0;j<m;j++) res+=s[i+j]!=t[j];
    chmin(ans,res);
  }
  cout<<ans<<newl;
  return 0;
}
