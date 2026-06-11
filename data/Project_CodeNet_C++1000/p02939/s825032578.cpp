#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string S;
  cin>>S;
  int ans=0;
  string SL="",TS="";
  rep(i,S.size()){
    TS+=S[i];
    if(TS==SL)continue;
    SL=TS;
    TS="";
    ans+=1;
  }
  cout<<ans<<endl;
}