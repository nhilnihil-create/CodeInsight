#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,K,S,k=1;
  cin>>N>>K>>S;
  if(S==1000000000)
    k=-1;
  for(int i=0;i<N;i++){
    if(i<K)
      cout<<S;
    else
      cout<<S+k;
    if(i!=N-1)
      cout<<' ';
    else
      cout<<endl;
  }
}