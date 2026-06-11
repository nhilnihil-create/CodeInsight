#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char a,b,x=0; cin>>b;
  for(int i=0;i<3;i++){
    a=b;
    cin>>b;
    x+= a==b?1:0;
  }
  if(x==0)cout<<"Good"<<endl;
  else cout<<"Bad"<<endl;
}