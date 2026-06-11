#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define int long long
//template
//main
signed main(){
  int N;string s;cin>>N>>s;
  int ans=1,l=0;
  for(int i=1;i<=N;i++)ans=ans*i%MOD;
  for(int i=0;i<2*N;i++){
    if((s[i]=='B')^(l&1))l++;
    else ans*=l--,ans%=MOD;
  }
  if(l)ans*=0;
  cout<<ans<<endl;
}
