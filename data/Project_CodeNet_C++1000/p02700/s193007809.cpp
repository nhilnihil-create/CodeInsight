#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  int turn = 0;
  while(1){
    
    turn++;
    c -= b;
    if(c <= 0) break;
    
    turn++;
    a -= d;
    if(a <= 0) break;
    
  }
  
  switch(turn % 2){
    case 0 : cout << "No" << endl; break;
    case 1 : cout << "Yes" << endl; break;
  }
    
}