#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	double a,b,h,m;
	double t1 = 2.0*M_PI/60.0;
	double t2 = 2.0*M_PI/(60.0*12);

	cin >> a >> b >> h >> m;

	double t = t1*m - t2*(60*h+m);


	double ans = sqrt(a*a + b*b - 2*cos(t)*a*b);

	printf("%.10f\n",ans);

	return 0;
}
