#include <bits/stdc++.h>
# define ll long long 
# define vi vector<int>
# define pii pair<int,int> 
#define mp make_pair
#define pb push_back
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	ll n , a, b ; 
	cin >> n >> a >> b ;
	ll ans = 1e18 ; 
	if(abs(a-b)%2 == 0)  {
		ans = min(ans , abs(a-b)/2) ; 
	} 
	ans = min(ans, min(a-1, n-b)+1 + (b-a-1)/2) ; 
	cout << ans ; 
	return 0 ; 
}
