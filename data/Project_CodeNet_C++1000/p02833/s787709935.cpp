#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAXX 500005
#define INF INT_MAX

#define PI   3.14159265358979323846264338327950

#define PB push_back
#define PF push_front
#define F first
#define S second

#define fixx(n) fixed << setprecision(n)

#define ll 	 long long

#define mod  1000000007


int main()
{
	FAST;
	ll n;
	cin >> n;
	if(n % 2 || n < 10){
		cout << 0;
		return 0;
	}
	ll ans = n/10;
	n /= 10;
	while(n ){
		n /= 5;
		ans += n;
	}
	cout << ans;
	return 0;
}