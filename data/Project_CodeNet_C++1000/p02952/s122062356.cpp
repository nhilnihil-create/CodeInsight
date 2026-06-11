#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;

int main() {
  int n;
  cin>>n;
  int ans=0;
  
  for(int i=1;i<=n;i++){
    int x=i;int a=0;
    while(x>0){
      x/=10;
      a++;
    }
    if(a%2==1)ans++;
  }
  
  cout<<ans<<endl;
    
  
}
