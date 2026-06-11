#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;

int main(){
  long long n;
  cin>>n;
  long long ans;
  bool ok=false;
 for(long long i=0;i<=n;i++){
    if(n<=i*1.08 && i*1.08<n+1){ok=true;
                  ans=i;
                  break;
                 }
  }
  if(ok)cout<<ans<<endl;
  else cout<<":("<<endl;
  
    
}
