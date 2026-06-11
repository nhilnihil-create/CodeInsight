#include <bits/stdc++.h>

#define fst first
#define snd second
#define ll long long
#define ld long double
#define pb push_back
#define emp emplace_back
#define pii pair<int, int>
#define usg unsigned
#define sg signed
#define mp make_pair

using namespace std;

void setIO(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
}

const ld PI = 4*atan((ld)1);
const int INF = 1e9+7;
const ll _INF = 1e18+7;


int main(){
	setIO();
	// g > r
	// b > g
	// b > g > r
	int r, g, b, k;
	cin >> r >> g >> b >> k;
	while (g <= r) k--, g*=2;
	while (b <= g) k--, b*=2;
	if (k < 0) cout << "No\n";
	else cout << "Yes\n";
}