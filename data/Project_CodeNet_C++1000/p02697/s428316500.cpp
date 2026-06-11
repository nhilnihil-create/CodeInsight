#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;

  vector<int> as(n),bs(n);
  if(n&1){
    for(int i=0;i<n;i++) as[i]=i,bs[i]=(n-1)-i;
  }else{
    for(int i=0;i<n;i++) as[i]=i,bs[i]=(n-1)-i;
    for(int i=n/4;i<n;i++) as[i]=i,bs[i]=(n-2)-i;
  }

  for(int i=0;i<m;i++) cout<<as[i]+1<<' '<<bs[i]+1<<newl;
  return 0;
}
