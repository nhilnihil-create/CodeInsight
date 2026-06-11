#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,ans=1;
  bool t=true;
  cin >> n;
  int64_t a[n];
  for(int64_t i=0;i<n;i++){
    cin >> a[i];
    if(a[i]==0){
      cout << 0 << endl;
      t=false;
      break;
    }
  }    
  if(t){
    for(int64_t i=0;i<n;i++){
      if(a[i]>1000000000000000000/ans){
        cout << -1 << endl;
        t=false;
        break;
      }
    ans*=a[i];
    }
  }
    
  if(t)cout << ans << endl;
}
    
    
