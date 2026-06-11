#include<bits/stdc++.h>
using namespace std;
#define M 998244353
int main(){
  long N;cin>>N;
  vector<long>D(N,0);long ans=true; bool c=true; 
  for(int i=0;i<N;i++){long a;cin>>a;D[a]++;if(i==0&&a!=0)ans=0;}
  ans*=(D[0]==1);
  for(int i=1;i<N;i++){//D[i-1]^D[i]
    if(D[i]==0)c=false;
    for(int _=0;_<D[i];_++)ans=(ans*D[i-1])%M;
    if(c==false && D[i]!=0)ans=0;
  }
  cout<<ans;
}