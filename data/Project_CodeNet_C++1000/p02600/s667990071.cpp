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
	int x; cin >> x;
	if (x >= 1800) cout << "1\n";
	else if (x >= 1600) cout << "2\n";
	else if (x >= 1400) cout << "3\n";
	else if (x >= 1200) cout << "4\n";
	else if (x >= 1000) cout << "5\n";
	else if (x >= 800) cout << "6\n";
	else if (x >= 600) cout << "7\n";
	else cout << "8\n";
}