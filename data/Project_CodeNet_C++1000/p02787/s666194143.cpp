#include <bits/stdc++.h>
using namespace std;
vector<int>DP(100001,1000000000);
int main(){
  int H,N;cin>>H>>N;
  vector<pair<int,int>>A(N);
  for(int i=0;i<N;i++)cin>>A[i].first>>A[i].second;
  DP[0]=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<N;j++)
      DP[min(i+A[j].first,H)]=min(DP[min(i+A[j].first,H)],DP[i]+A[j].second);
  }
  cout<<DP[H]<<endl;
}