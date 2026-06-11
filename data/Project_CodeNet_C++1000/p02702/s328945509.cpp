/*
ID: victorn2
LANG: C++
TASK: heritage
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <chrono>
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define ll long long
#define f first
#define fin cin
#define fout cout
#define s second
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define debug(x) cout << "DEBUG " << x << endl
#define debug2(x, y) cout << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cout << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
#define int long long
#define left vadia
#define right puta
using namespace std;
typedef pair<ll, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9+7;
const int MAXN = 1e5+5;
const int MAXV = 1e6+5;
typedef vector<int> vi;
typedef pair<vi, string> pvs; 

int32_t main() {

	string s;
	cin >> s;
	int n = s.size();

	int x = 0, pot = 1;
	vector<int> v(2020);

	v[0]++;
	int ans = 0;
	for(int i = n-1; i >= 0; i--) {
		x = (x + (s[i] - '0') * pot) % 2019;
		pot = (pot * 10) % 2019;
		ans += v[x];
		v[x]++;
	}

	cout << ans << endl;
}