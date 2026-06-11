#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int s=0,x=0;
  for(int i=0;i<105;i++){
    s+=b;
    x+=d;
    if(s>=c){
      cout<<"Yes"<<endl;
      break;
    }
    if(x>=a){
      cout<<"No"<<endl;
      break;
    }
  }
}