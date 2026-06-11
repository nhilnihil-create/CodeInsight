#include<bits/stdc++.h>
using namespace std;
int main(void){
  int k,a,b;cin>>k>>a>>b;
  if(a%k==0||b%k==0) cout<<"OK"<<endl;
  else if(a/k<b/k) cout<<"OK"<<endl;
  else cout<<"NG"<<endl;
  return 0;
}