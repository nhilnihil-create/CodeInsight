#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXX 100005
#define PI 3.14159265358979323846264338327950
#define ll signed long long int
using namespace std;
ll t , n, k,  x = 0, y = 2, m, ans = 0,h,s ;
ll a[MAXX], b[MAXX], c[MAXX];
double f = 0.5;
vector<ll> adj[MAXX];
bool used[MAXX];
ll d[MAXX];
ll p[MAXX];
queue<ll> q;

signed main()
{
	FAST;
	cin >> n;
	string str;
	cin >> str;
	if(n >= 3200){
		cout << str;
		return 0;
	}
	cout << "red";
}