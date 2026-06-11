#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int H,N,ma=0;
  cin>>H>>N;
  vector<pair<int,int>> A(N);
  for(pair<int,int> &p:A){
    cin>>p.first>>p.second;
    ma=max(ma,p.first);
  }
  vector<int> B(H+ma,1000000000);
  B[0]=0;
  for(int i=1;i<H+ma;i++)
    for(pair<int,int> p:A)
      if(i-p.first>=0)
        B[i]=min(B[i],B[i-p.first]+p.second);
  int ans=1000000000;
  for(int i=0;i<ma;i++)
    ans=min(ans,B[H+i]);
  cout<<ans<<endl;
}