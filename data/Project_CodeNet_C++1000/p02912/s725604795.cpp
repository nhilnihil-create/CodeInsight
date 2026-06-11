#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,M;
  cin>>N>>M;
  priority_queue<int> A;
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    A.push(j);
  }
  for(int i=0;i<M;i++){
    A.push(A.top()/2);
    A.pop();
  }
  int j=0;
  while(!A.empty()){
    j+=A.top();
    A.pop();
  }
  cout<<j<<endl;
}