#include<bits/stdc++.h>
using namespace std;
int main(){
  long long  a ; string b; cin>>a; cin>>b;
  long long num1=0,num2=0,flag=0;
  for(int i=0;i<b.length();i++){
  	if(b[i]=='.')flag=1;
  	else if(flag) num2=num2*10+(b[i]-'0');
  	else num1=num1*10+(b[i]-'0');
  }
  cout<<(a*num1)+(a*num2)/100<<endl;
}
  
