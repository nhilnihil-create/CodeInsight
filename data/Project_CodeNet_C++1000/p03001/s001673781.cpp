#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	double w,h,x,y;
	cin >> w >> h >> x >> y;
	double ans = w*h/2;
	double num = (w == x*2 && h == y*2) ? 1 : 0;
	cout << fixed << setprecision(15) << ans;
	cout << " " << (int)num << endl;
}

// cout << fixed << setprecision(15) <<  << endl;