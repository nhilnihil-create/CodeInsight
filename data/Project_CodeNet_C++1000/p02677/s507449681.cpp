#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double PI = acos(-1);

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	double a, b, h, m;
	cin >> a >> b >> h >> m;
	double time = h * 60 + m;
	double ax = a * sin(time/(12*60)*2*PI);
	double ay = a * cos(time/(12*60)*2*PI);
	double bx = b * sin(m/60*2*PI);
	double by = b * cos(m/60*2*PI);
	double ans = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}