#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;


int main(){
	int a,b,h,m;
	cin >> a >> b >> h >> m;
	double alpha = (h/12.0 + m/12.0/60.0) * 2.0 * M_PI;
	double beta = (m/60.0) * 2.0 * M_PI;
	double ans;
	ans = a*a + b*b - 2.0*a*b*cos(beta-alpha);
	printf("%.12lf\n",sqrt(ans));
	return 0;
}