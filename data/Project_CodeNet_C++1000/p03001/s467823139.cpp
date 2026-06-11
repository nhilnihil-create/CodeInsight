#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	LL w,h,x,y;
	// nyuryoku
	cin >> w >> h >> x >> y;
	// keisan
	double ans;
	ans = (double)w*h/2;
	int flag = (x + x == w)&&(y + y == h);
	printf("%lf %d\n",ans,flag);
	// syutsuryoku
}