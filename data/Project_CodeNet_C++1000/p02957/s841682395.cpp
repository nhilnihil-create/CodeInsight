#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXX 100005
#define PI 3.14159265358979323846264338327950
#define ll signed long long int
using namespace std;
ll t , n, k,   y = 2, m,h,s , ans =0;
ll a[MAXX] = {0}, b, c[MAXX];
vector<ll> adj[MAXX];
bool used[MAXX];


signed main()
{
	FAST;
	cin >> t >> n;
	if((t+n )% 2 == 0){
		cout << (t+n )  /2;
	}
	else{
		cout << "IMPOSSIBLE";
	}
}