#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int X;
  cin>>X;
  int N=pow(X,0.2);
  for(int i=0;i<=N;i++)
    for(int j=i;j<=N;j++)
      if(i*i*i*i*i+j*j*j*j*j==X){
        cout<<i<<' '<<0-j<<endl;
        return 0;
      }
  int M=0;
  while(M*M*M*M*M-(M-1)*(M-1)*(M-1)*(M-1)*(M-1)<=X)
    M++;
  for(int i=0;i<=M;i++)
    for(int j=0;j<=i;j++)
      if(i*i*i*i*i-j*j*j*j*j==X){
        cout<<i<<' '<<j<<endl;
        return 0;
      }
}