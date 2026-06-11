#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main(){
  long double W = 0, H = 0, x = 0, y = 0;
  cin >> W >> H >> x >> y;
  cout << fixed << setprecision(12);
  cout << (W*H)/2 << " ";
  if(W/2 == x && H/2 == y){
    cout << "1";
  }
  else{
    cout << "0";
  }
}