#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  int ans=0;
  bool ncan=true;
  while(ncan){
    ans++;
    if(ans*108/100==N) ncan=false;
    if(ans==50000) break;
  }
  if(ncan) cout<<":("<<endl;
  else cout<<ans<<endl;
}
  
