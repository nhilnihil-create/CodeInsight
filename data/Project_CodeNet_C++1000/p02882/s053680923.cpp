#include <bits/stdc++.h>
# define ll long long 
# define vi vector<int>
# define pii pair<int,int> 
#define mp make_pair
#define pb push_back
# define PI acos(-1)
# define double long double
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	double a,b,x ; 
	cin >> a >> b >> x ; 
	double ans ; 
	double v = (a*a*b) / 2 ; 
	if( v > x ) {
		ans = (PI / 2) - atan((2*x) /(b*b*a)); 
	} else {
		ans =  atan((2*a*a*b - 2*x)/(a*a*a)) ; 
	}
	cout << fixed << setprecision(10) << (ans *180 )/ PI ; 
	return 0 ; 
}

