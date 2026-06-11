#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int unit=n%10;
  if(unit==2||unit==4||unit==5||unit==7||unit==9)cout<<"hon";
  else if(unit==0||unit==1||unit==6||unit==8)cout<<"pon";
  else cout<<"bon";
  return 0;}
