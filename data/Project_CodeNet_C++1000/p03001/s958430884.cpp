#include <bits/stdc++.h>
using namespace std;
 
int main(){
  double w,h;
  int x,y;
  cin >> w >> h >> x >> y;
  cout << (w * h) / 2 << " " ;
  if(w == 2*x && h == 2*y){
    cout << 1;
  }else{
    cout << 0;
  }
}