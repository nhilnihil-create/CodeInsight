#include <bits/stdc++.h>
using namespace std;

# define ll long long 
# define VI vector<int>
# define VLL vector<ll>
# define PII pair<int,int> 
#define mp make_pair
#define pb push_back
# define PI acos(-1)
# define double long double
const int MxN = 200005 ; 


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	
	ll n ;
	cin >> n ; 
	if(n % 2 != 0)
		cout << 0 ; 
	else {
		ll ans = 0 ;
		ll num = 10 ; 
		while(num <= n) {
			ans += n / num ; 
			num *= 5 ; 
		}
		cout << ans ; 
		
	}
	
	return 0 ; 
}

