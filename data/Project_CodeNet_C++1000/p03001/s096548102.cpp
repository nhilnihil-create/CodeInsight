#include <bits/stdc++.h>
using namespace std;
 
int main() {
long long W,H,x,y;
  cin >> W >> H >> x >> y;
  long long a = W * H;
  
  cout << a / 2;
  if(a % 2 == 1)cout << ".5";
  if(x * 2 == W&&y * 2 == H){
   cout << " " << 1; 
  }else{
   cout <<" " << 0; 
  }
}