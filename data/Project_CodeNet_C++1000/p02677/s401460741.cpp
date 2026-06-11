#include <iostream>
#include <iomanip>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

const long double PI = 3.14159265358979323846;
long double A, B, H, M;
int main() {
	cin >> A >> B >> H >> M;
	long double a = ((60*H) + M)/720 * 2*PI;
	long double b = (M/60) * 2*PI;

	long double rad = abs(a-b);
	long double ans = A*A + B*B - 2*A*B*cos(rad);
	ans = sqrt(ans);
	cout << fixed << setprecision(20) << ans << endl;

    return 0;
}
