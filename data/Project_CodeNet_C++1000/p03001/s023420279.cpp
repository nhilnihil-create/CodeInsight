#include <bits/stdc++.h>
using namespace std;

int main() {
	int h,w,x,y;
	cin >> w >> h >> x >> y;
	double s=(double)h*w/2;
	char p='0';
	if(x*2==w&&y*2==h)
	{
		p='1';
	}
	cout << fixed << setprecision(15) << s << ' ' << p << endl;
	return 0;
}
