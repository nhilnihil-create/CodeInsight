#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
signed main(){
  string S;
  cin>>S;
  reverse(S.begin(),S.end());
  int N=S.size();
  vector<vector<int>> A(N+1,vector<int>(13,0));
  A[0][0]=1;
  for(int i=1,k=1;i<=N;i++,k=k*10%13){
    if(S[i-1]!='?'){
      int n=(S[i-1]-'0')*k%13;
      for(int j=0;j<13;j++)
        A[i][(j+n)%13]=(A[i][(j+n)%13]+A[i-1][j])%mod;
    }else{
      for(int n=0;n<10;n++)
        for(int j=0;j<13;j++)
          A[i][(j+n*k)%13]=(A[i][(j+n*k)%13]+A[i-1][j])%mod;
    }
  }
  cout<<A[N][5]<<endl;
}