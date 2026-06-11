#include <bits/stdc++.h>
using namespace std;
int main(void){
  int x,y;
  cin >> x >> y;
  int awa = 0;
  if(x < 4 && y < 4){
   awa = (-1*x+4)*100000 + (-1*y+4)*100000;
 }
  else if(x < 4) awa = (-1*x+4)*100000;
  else if(y < 4) awa = (-1*y+4)*100000;
  if(x == 1 && y == 1) awa += 400000;
  cout << awa << endl;
}