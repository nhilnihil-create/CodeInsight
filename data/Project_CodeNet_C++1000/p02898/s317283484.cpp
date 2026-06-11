#include<iostream>
using namespace std;
int main(){
  int n,k,ans=0;
  cin>>n>>k;
  while(n--){
    int q;cin>>q;
    if(q>=k)ans++;
  }
  cout<<ans;
  return 0;
}
  