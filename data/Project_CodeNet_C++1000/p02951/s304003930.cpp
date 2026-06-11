#include "iostream"
using namespace std;
int main(){
  int a;int b;int c;
  cin>>a>>b>>c;
  int d=c-(a-b);
  if(d<=0){
    cout<<0<<endl;
  }
  else{
    cout<<d<<endl;
  }
}
