#include<bits/stdc++.h>
using namespace std;
int main(){
  int w,h,x,y;
  cin >> w >> h >> x >> y;
  cout << fixed << setprecision(10) ;
  cout << (double)((double)w*(double)h)/2 << " " << ((x+x==w && y+y==h)?1:0) << endl;
}
