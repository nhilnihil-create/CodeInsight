#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,D,A;
  cin>>N>>D>>A;
  vector<pair<int,int>> B(N);
  for(pair<int,int> &p:B)
    cin>>p.first>>p.second;
  sort(B.begin(),B.end());
  vector<int> C(N+2,0);
  int ans=0;
  for(int i=0;i<N;i++){
    C[i+1]+=C[i];
    B[i].second-=C[i+1];
    if(B[i].second<=0)
      continue;
    int K=(B[i].second+A-1)/A;
    ans+=K;
    C[i+1]+=K*A;
    C[(upper_bound(B.begin(),B.end(),make_pair(B[i].first+D*2,1000000000LL))-B.begin())+1]-=K*A;
  }
  cout<<ans<<endl;
}