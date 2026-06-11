#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> p;


int main(void){
	ll w, h, x, y;
  cin >> w >> h >> x >> y;
  double s = (double)((w * h)/ 2.0);
  cout << fixed << setprecision(10) << s<< " ";
  int a = 0;
  if(2*x == w && 2*y == h) a = 1;
  cout << a;
  
}
