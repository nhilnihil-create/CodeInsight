#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,Q;
  cin>>N>>Q;
  vector<set<int>> A(N);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    A[a-1].insert(b-1);
    A[b-1].insert(a-1);
  }
  vector<int> B(N);
  for(int i=0;i<Q;i++){
    int p,x;
    cin>>p>>x;
    B[p-1]+=x;
  }
  queue<int> C;
  C.push(0);
  vector<bool> D(N,true);
  while(!C.empty()){
    int I=C.front();
    C.pop();
    D[I]=false;
    for(int i:A[I])
      if(D[i]){
        C.push(i);
        B[i]+=B[I];
      }
  }
  for(int i=0;i<N;i++){
    cout<<B[i];
    if(i==N-1)
      cout<<endl;
    else
      cout<<' ';
  }
}