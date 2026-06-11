#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,M,K;
  
  cin>>N>>M>>K;
  vector<int>A(N+1);vector<int>B(M+1);vector<int>C(N+1);vector<int>D(M+1);
  for(int i=1;i<=N;i++){cin>>A[i];C[i]=C[i-1]+A[i];}
  for(int i=1;i<=M;i++){cin>>B[i];D[i]=D[i-1]+B[i];}
  vector<int>E(N+1,0);
  int count=M;
  for(int i=0;i<=N;i++){
    for(int j=count;j>=0;j--){
      if(K>=C[i]+D[j]){E[i]=i+j;count=j;break;}
    }
  }
  sort(E.begin(),E.end());
  cout<<E[N]<<endl;
}
