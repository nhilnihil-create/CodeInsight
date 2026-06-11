#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b;
  cin >> a >> b;
  
  int x = 0;
  for(x = 0; x <= 1000; x++){
    if( ((int)(x*0.08) == a ) && ((int)(x * 0.1) == b ) ){
      break;
    }
  }
  
  if(x > 1000){
    x = -1;
  }
  
  cout << x << endl;
}