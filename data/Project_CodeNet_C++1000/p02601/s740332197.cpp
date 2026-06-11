#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,c; //a red, b green, c blue
  cin >> a >> b >> c; //a < b < c
  
  int k;
  cin >> k;
  
  int count = 0;
  while(a >= b){
    b *= 2;
    count++;
  }
  while(b >= c){
    c *= 2;
    count++;
  }
  
  if(count <= k){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  
}