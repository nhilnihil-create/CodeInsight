#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define all(v)    ((v.begin()),(v.end()))
#define sz(v)     ((int)(v.size()))
#define forv(i, v) for(int i = 0; i < sz(v); ++i)
#define forn(i,n)   for(int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long       ll;
typedef long double     ld;
typedef vector<int>     vi;
typedef vector<double>  vd;
typedef vector< vi >    vii;
typedef vector< vd >    vdd;
typedef vector<string>  vs;


int main()
{
	fast;
	ll x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	vector<int> v, v1, v2;
	for (int i = 0; i < a ; i++) {
		ll x;
		cin >> x;
		v1.push_back(x);
	}
	for (int i = 0; i  < b; i++) {
		ll x;
		cin >> x;
		v2.push_back(x);
	}
	for (int i = 0; i < c; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}
	ll ans = 0;
	sort(v1.rbegin(), v1.rend());
	sort(v2.rbegin(), v2.rend());
	for (int i = 0; i < x; i++) v.push_back(v1[i]);
	for (int i = 0; i  < y; i++) v.push_back(v2[i]);
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < (x + y); i++) {
		ans += v[i];
	}
	cout << ans << endl;

	return 0;
}
