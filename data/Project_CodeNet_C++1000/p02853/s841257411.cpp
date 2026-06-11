#include <bits/stdc++.h>
using namespace std;
int main (){
  int a,b;
  int c=0;
  cin>>a>>b;
  int i;
    switch (a){
      case 1:
        c+=300000;
        break;
      case 2:
        c+=200000;
        break;
      case 3:
        c+=100000;
        break;
      default:
        break;
    }
  switch (b){
      case 1:
        c+=300000;
        break;
      case 2:
        c+=200000;
        break;
      case 3:
        c+=100000;
        break;
      default:
        break;
    }
  if(a==b&&a==1)
    c+=400000;
  cout<<c;
  return 0;
}