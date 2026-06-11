#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  
  int flag = 0;
  while( (a > 0) && (c > 0) ){
    c -= b;
    if(c <= 0){
      flag = 1;
      break;
    }
    a -= d;
    if(a <= 0){
      break;
    }
  }//while
  
  if(flag == 1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}