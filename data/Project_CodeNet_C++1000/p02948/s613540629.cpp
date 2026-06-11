#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,M;
  cin>>N>>M;
  vector<vector<int>> A(M+1);
  for(int i=0;i<N;i++){
    int a,b;
    cin>>a>>b;
    if(a<=M)
      A[a].push_back(b);
  }
  priority_queue<int> B;
  int k=0;
  for(int i=1;i<=M;i++){
    for(int j:A[i])
      B.push(j);
    if(!B.empty()){
      k+=B.top();
      B.pop();
    }
  }
  cout<<k<<endl;
}