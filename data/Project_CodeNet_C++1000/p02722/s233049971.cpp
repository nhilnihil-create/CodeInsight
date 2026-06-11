#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,ans=0;
  cin>>N;
  for(int i=2;i<=N/i;i++){
    if(N%i==0){
      int j=N;
      for(;j%i==0;j/=i);
      if(j%i==1)
        ans++;
    }
  }
  N--;
  for(int i=1;i<=N/i;i++){
    if(N%i==0)
      ans+=2;
    if(i*i==N)
      ans--;
  }
  cout<<ans<<endl;
}