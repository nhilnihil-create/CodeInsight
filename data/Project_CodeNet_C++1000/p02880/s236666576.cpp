#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b;
  cin>>a;
  bool ok=false;
  for(int i=1;i<=9;i++){
    if(a%i==0&&a/i<10)
      ok=true;
  }
  if(ok)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}