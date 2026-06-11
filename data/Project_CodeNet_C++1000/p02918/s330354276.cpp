#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,K,ans=0;
  char c='a';
  cin>>N>>K>>c;
  for(int i=1;i<N;i++){
    char a;
    cin>>a;
    if(c==a)ans++;
    c=a;
  }
  cout<<min(ans+2*K,N-1)<<endl;
}