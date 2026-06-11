#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int M,D,ans=0;
  cin>>M>>D;
  for(int i=1;i<=M;i++){
    for(int j=22;j<=D;j++){
      int k=j/10,l=j%10;
      if(k>1 && l>1 && k*l==i)
        ans++;
    }
  }
  cout<<ans<<endl;
}