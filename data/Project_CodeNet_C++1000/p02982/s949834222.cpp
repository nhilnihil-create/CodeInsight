#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,D;
  cin>>N>>D;
  vector<vector<int>> A(N,vector<int>(D));
  for(int i=0;i<N;i++)
    for(int j=0;j<D;j++)
      cin>>A[i][j];
  int ans=0;
  for(int i=0;i<N;i++)
    for(int j=i+1;j<N;j++){
      int l=0;
      for(int k=0;k<D;k++)
        l+=(A[i][k]-A[j][k])*(A[i][k]-A[j][k]);
      if(pow(l,0.5)==(int)pow(l,0.5))
        ans++;
    }
  cout<<ans<<endl;
}