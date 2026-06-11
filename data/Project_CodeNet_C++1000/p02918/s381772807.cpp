#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,K,ans=0;
  string S;
  cin>>N>>K>>S;
  for(int i=1;i<N;i++)
    if(S[i-1]!=S[i])
      ans++;
  ans-=K*2;
  cout<<N-max(0LL,ans)-1<<endl;
}