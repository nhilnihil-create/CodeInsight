#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  bool A=false;
  cin>>a>>b>>c;
  for(int i=b;i<=c;i++){
    if(i%a==0){
      cout<<"OK"<<endl;
      A=true;
      break;
    }
  }
  if(A==false)cout<<"NG"<<endl;
}