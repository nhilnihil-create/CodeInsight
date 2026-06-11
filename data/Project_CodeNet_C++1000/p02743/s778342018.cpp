#include <bits/stdc++.h>
# define ll long long 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	
	ll a , b , c ; 
	cin >> a >> b >> c ; 
	ll l = a*a + b*b + c*c + 2*a*b - 2*b*c - 2*a*c ; 
	ll r = 4 *a*b ; 
	if(a > c || b > c) {
		cout <<"No";
		return 0 ;
	}
	//cout << l << " " << r << endl ; 
	if(l > r) 
		cout << "Yes"; 
	else
		cout << "No" ; 
	return 0 ; 
}
