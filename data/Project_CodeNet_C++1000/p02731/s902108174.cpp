#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using p = pair<int,int>;

int main(){
	double L;
	cin >> L;
	double x, y, z;
	x = L / 3;
	y = L / 3;
	z = L - 2*x;
	printf("%.10lf\n",x*y*z);
	return 0;
}

