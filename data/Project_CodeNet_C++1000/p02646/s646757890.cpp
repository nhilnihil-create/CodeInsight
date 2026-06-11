#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int a,v,b,w,t;
  cin>>a>>v>>b>>w>>t;

  if(v<=w) drop("NO");
  Int d=abs(a-b);
  Int s=v-w;
  if(s*t>=d) drop("YES");
  drop("NO");
  return 0;
}
