#include<bits/stdc++.h>

using namespace std;

int main(){

  int n,op;
  cin>>n;
  op = n%10;
  if(op==2||op==4||op==5||op==7||op==9)
    cout<<"hon";
  else if(op==0||op==1||op==6||op==8)
    cout<<"pon";
  else
    cout<<"bon";
  return 0;

}