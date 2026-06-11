#include <bits/stdc++.h>
using namespace std;

int main()
{
  int L;
  cin >> L;
  
  long double vol = 0;
  if( L % 3 == 0){
    vol = (long double)((L / 3) * (L / 3) * (L / 3));
  }else{
    vol = (long double)(((long double)L / 3.00000000000) * ((long double)L / 3.0000000000000) * ((long double)L / 3.00000000000)); 
  }
  
  cout << fixed;
  cout << setprecision(20);
  cout << (long double)vol << endl;
}