#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,M;
  cin>>N>>M;
  if(M%2){
    for(int i=0;i<M/2;i++)cout<<i+1<<' '<<M-i<<'\n';
    for(int i=0;i<M/2+1;i++)cout<<M+i+1<<' '<<2*M+1-i<<'\n';
  }else{
    for(int i=0;i<M/2;i++)cout<<i+1<<' '<<M-i<<'\n';
    for(int i=0;i<M/2;i++)cout<<M+1+i<<' '<<2*M+1-i<<'\n';
  }
}