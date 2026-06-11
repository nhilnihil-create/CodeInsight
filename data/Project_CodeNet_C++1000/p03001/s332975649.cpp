#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	double W,H,x,y;
  cin >> W >> H >> x >> y;
  printf("%.11f %d", W * H / 2,(x*2 == W) && (y * 2 == H));
return 0;
}