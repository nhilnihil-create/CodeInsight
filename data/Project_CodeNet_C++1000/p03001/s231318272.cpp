#include<bits/stdc++.h>
using namespace std;

int main(){
  double w, h, x, y;
  cin >> w >> h >> x >> y;
  if(x == w / 2.0 && y == h / 2.0){
    cout << fixed << setprecision(100) << (double)(w * h / 2.0) << " " << 1 << endl;
  }else{
    cout << fixed << setprecision(100) << (double)(w * h / 2.0) << " " << 0 << endl;
  }
}