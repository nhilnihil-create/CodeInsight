#include<bits/stdc++.h>
using namespace std;
int main(){
  int x; cin >>x;
  int y; cin >>y;
  int prise =0;
  bool win = false;
  if(x < 4){
    if(x == 3) prise += 100000;
    if(x == 2) prise += 200000;
    if(x == 1) {prise += 300000;win=true;}
  }
  if(y < 4){
    if(y == 3) prise += 100000;
    if(y == 2) prise += 200000;
    if(y == 1) {prise += 300000;if(win==true)prise += 400000;}
  }
  cout << prise;
  return 0;
}