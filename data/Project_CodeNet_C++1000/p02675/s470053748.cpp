#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  n%=10; string s;
  if(n==3) s="bon";
  else if(n==0||n==1||n==6||n==8) s="pon";
  else s="hon";
  cout<<s<<endl;
  return 0;
}