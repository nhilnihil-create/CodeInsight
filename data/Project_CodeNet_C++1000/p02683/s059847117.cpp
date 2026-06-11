#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M,X;
  cin>>N>>M>>X;
  vector<vector<int>> A(N,vector<int>(M));
  vector<int> B(N);
  for(int i=0;i<N;i++){
    cin>>B[i];
    for(int j=0;j<M;j++)cin>>A[i][j];
  }
  int mn=10000000;
  for(int b=0;b<(1<<N);b++){
    bitset<12> C(b);
    vector<int> D(M,0);
    int cnt=0;
    for(int i=0;i<N;i++)
      if(C.test(i)){
        cnt+=B[i];
        for(int j=0;j<M;j++)
          D[j]+=A[i][j];
      }
    int c=10000000;
    for(int &i:D)
      c=min(i,c);
    if(c>=X)
      mn=min(mn,cnt);
  }
  if(mn==10000000)puts("-1");
  else cout<<mn<<endl;
}