#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXX 100005
#define PI 3.14159265358979323846264338327950
#define ll signed long long int
using namespace std;
ll t , n, k,   y = 2, m, ans = 0,h,s ;
double a[MAXX], b[MAXX], c[MAXX];
double f = 0, x;
vector<ll> adj[MAXX];
bool used[MAXX];
ll d[MAXX];
ll p[MAXX];
queue<ll> q;

signed main()
{
	FAST;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> x;
		x = 1/x;
		f += x;
	}
	f= 1/f;
	cout << fixed << setprecision(14) <<  f;
}