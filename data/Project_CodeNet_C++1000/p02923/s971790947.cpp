#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,a=1e9,b,ans=0,d=-1;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> b;
    if(a>=b){
      d++;
    }else{
      ans=max(ans,d);
      d=0;
    }
    a=b;
  }
  ans=max(ans,d);
  cout << ans << endl;
  return 0;
}