#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  long long W,H,x,y;  cin >> W >> H >> x >> y;
  cout << fixed << setprecision(15) << (double)W*H/2 << ' ';
  if(2*x == W && 2*y == H)  cout << '1' << endl;
  else cout << '0' << endl;
}
