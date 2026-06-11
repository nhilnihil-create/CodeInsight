#include<iostream>
using namespace std;

int gcd(int a,int b){
  if(a%b!=0) gcd(b,a%b);
  else return b;
}



int main(){
  int a,b,ans;
  cin>>a>>b;
 ans=gcd(a,b);
 cout<<ans<<endl;
  return 0;
}