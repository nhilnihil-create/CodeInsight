
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
	double a,b,x;
	cin >> a >> b >> x;
	double pi = 3.141592653589793238;
	cout << fixed << setprecision(10);
	if((a*a*b)/2.0>=x) cout << atan2(a*b*b,x*2)*180/pi << endl;
	else cout << atan2(2*(a*a*b-x),a*a*a)*180/pi << endl;
}
