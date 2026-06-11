#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int main() {
	double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	x2 -= x1; y2 -= y1;
	printf("%.7lf\n", sqrt(x2*x2 + y2*y2));
}