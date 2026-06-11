#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;cin>>N;
  vector<pair<string,int>>V(N);for (int i=0;i<N;i++)cin>>V[i].first>>V[i].second;
  string X;cin>>X;
  int T;
  for(int i=0;i<N;i++){
    if(V[i].first==X)T=i;
  }
  int sum=0;
  for(int i=T+1;i<N;i++){
    sum+=V[i].second;
  }
  cout<<sum<<endl;
}