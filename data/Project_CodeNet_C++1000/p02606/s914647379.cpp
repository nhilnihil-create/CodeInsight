#include <bits/stdc++.h>
using namespace std;

int main()
{
  int L,R,d;
  cin >> L >> R >> d;
  
  int mul;
  int num = 0;
  for(int i = 1; i <= R; i++){
    mul = i * d;
    if( (mul >= L) && (mul <= R) ){
      num++;
    }//if
  }//for
  
  cout << num << endl;
    
}