#include<bits/stdc++.h>
using namespace std;


int main(){
  
  long long W, H, x, y;
  int flag = 0;
  cin >> W >> H >> x >> y;
 
  
  if(2 * x == W && 2 * y == H){
    flag = 1;
  }
  
  cout << (long double) W * H / 2 << " " << flag << endl; 
}