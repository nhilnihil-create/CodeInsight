#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAXX 100005
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
	
	ll n, m;
	cin >> n >> m;
	
	ll ans = 2020;
	if(m - n >= 2019 ){
		cout << 0; return 0;
	}
	for(ll i = n; i <= m; i ++){
		for(ll j = i + 1; j <= m; j ++){
			if((i * j) % 2019 < ans) 
				ans = i*j  % 2019;
			
		}
		
	}
	cout << ans;
	return 0;
	
}