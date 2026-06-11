#include <bits/stdc++.h>
using namespace std;

int main(){
  long double a,b,c;
  cin>>a>>b>>c;
  if((c-a-b)>=0){
    if(4*a*b<(c-a-b)*(c-a-b)){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
  if((c-a-b)<0){
      cout<<"No"<<endl;
  }
}