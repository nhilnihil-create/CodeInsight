#include<bits/stdc++.h>
using namespace std;

#define  ll long long
#define  il inline
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dep(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back

const int mod = 1e9 + 7;
const int maxn = 1e3 + 10;
const int maxm = 2e5 + 10;
const double PI = acos(-1.0);

struct point{
	double x,y;
}s[maxn];

bool cmp(point &a, point &b) {
	if(atan2(a.y,a.x) != atan2(b.y,b.x)) return atan2(a.y,a.x) < atan2(b.y,b.x);
	return a.x < b.x;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
   	int n;
   	cin >> n;
   	rep(i,1,n) cin >> s[i].x >> s[i].y;
   	sort(s + 1, s + 1 + n , cmp);
   	rep(i,1,n) s[i + n] = s[i];
   	double ans = 0;
   	rep(i,1,n) {
   		double xx = 0, yy = 0;
   		rep(j,i,i + n - 1) {
   			 xx += s[j].x;
   			 yy += s[j].y;
   			 ans = max(ans, xx * xx + yy * yy);
   		}
   	}
   	cout << setprecision(30) << sqrt(ans) << endl;
    return 0;
}