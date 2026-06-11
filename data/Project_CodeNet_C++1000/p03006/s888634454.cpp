#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<pair<int,int>> A(N);
  for(pair<int,int> &p:A)cin>>p.first>>p.second;
  map<pair<int,int>,int> B;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      if(i==j)continue;
      B[make_pair(A[i].first-A[j].first,A[i].second-A[j].second)]++;
    }
  int mx=0;
  for(pair<pair<int,int>,int> p:B)
    mx=max(mx,p.second);
  cout<<N-mx<<endl;
}