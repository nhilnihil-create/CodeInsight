#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;
 
int main() {
  int n;
  cin >> n;

  int floor,cap;

  floor = ((100 * n) + 108 -1) / 108;
  
  if((100 * (n + 1) % 108 == 0)){
     cout << ":(" << endl;
     return 0;
  }
  
  cap = (100 * (n + 1)) / 108;
 
  if(floor == cap){
      cout << floor << endl;
  }else{
      cout << ":(" << endl;
  }
  
}