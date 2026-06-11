#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  vector<vector<int>> A(N,vector<int>(0));
  vector<pair<int,int>> B(N-1);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    A[a-1].push_back(b-1);
    A[b-1].push_back(a-1);
    B[i]=make_pair(a-1,b-1);
  }
  int K=0;
  for(int i=0;i<N;i++)
    K=max(K,(int)(A[i].size()));
  cout<<K<<endl;
  queue<int> C;
  C.push(0);
  vector<int> D(N,-1);
  D[0]=0;
  map<pair<int,int>,int> E;
  while(!C.empty()){
    int I=C.front(),k=1;
    C.pop();
    for(int i:A[I]){
      if(D[I]==k)
        k++;
      if(D[i]==-1){
        C.push(i);
        D[i]=k;
        E[make_pair(I,i)]=k;
        k++;
      }
    }
  }
  for(pair<int,int> p:B)
    cout<<max(E[p],E[make_pair(p.second,p.first)])<<endl;
}