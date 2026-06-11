#include <bits/stdc++.h>

/*                    ॐ Shree ॐ                     */
/* ॐ ॐ ॐ
ॐ भूर् भुवः स्वः
तत् सवितुर्वरेण्यं
भर्गो देवस्य धीमहि
धियो यो नः प्रचोदयात्
*/
using namespace std;
typedef long long int ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
// online submission
#endif
	long long int a,b,c,d;
	cin>>a>>b>>c>>d;
	setprecision(100);
	fixed;
	long double minute=c*60.000+d;
	long double hourhand=(360.0/(12.0*60.000))*minute;
	long double minhand=(360.000/60.000)*d;
	long double angle=abs(hourhand-minhand);
	angle=min(angle,360-angle);
	angle*=(3.141592653589793238)/180.0;
	cout<<setprecision(100)<<sqrt(a*a+b*b-2*a*b*cos(angle));
}