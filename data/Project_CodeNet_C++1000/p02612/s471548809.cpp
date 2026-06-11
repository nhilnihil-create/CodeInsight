#include<iostream>

using namespace std;

int main(){
 int n;
  cin>>n;
  int ans = 1000-n%1000;
  if(ans % 1000 == 0) cout<<0<<endl;
  else cout<<ans<<endl;
  
  return 0;
}