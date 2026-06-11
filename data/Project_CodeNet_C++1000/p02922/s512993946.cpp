#include <bits/stdc++.h>

using namespace std;

int main(){

  int i,j,c=1,p=0;
  cin>>i>>j;

  while (1){
    if ( c >= j){
      break;
    }
    c--;
    c +=i;
    p +=1;
  }
  cout<<p;

  return 0;
}
