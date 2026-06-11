#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B;
  cin>>A>>B;
  int ans=(A+B)/2;
  int q=(A+B)%2;
  if(q==0) cout<<ans<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
}