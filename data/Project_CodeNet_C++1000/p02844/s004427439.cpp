#include<bits/stdc++.h>
using namespace std;
int main(){
  long N;cin>>N;
  string S;cin>>S;
  
  vector<bitset<10>>A(N),B(N);
  for(long i=1;i<N;i++){
    A[i]=A[i-1];A[i].set(S[i-1]-48);
  }
  for(long i=N-2;i>=0;i--){
    B[i]=B[i+1];B[i].set(S[i+1]-48);
  }
  vector<vector<vector<bool>>>C(10,vector<vector<bool>>(10,vector<bool>(10)));
  for(long i=0;i<N;i++)for(long j=0;j<10;j++)for(long k=0;k<10;k++){
    if(A[i].test(j)&&B[i].test(k))C[j][S[i]-48][k]=1;
    
  }
  long ans=0;
  for(long i=0;i<10;i++)for(long j=0;j<10;j++)for(long k=0;k<10;k++)if(C[i][j][k])ans++;
  cout<<ans<<endl;
  
  
}

/*


*/