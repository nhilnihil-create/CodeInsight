#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 1000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)

int main() {
	int a, b; cin >> a >> b;
	char s1[10], s2[10];
	char *ans = s1;
	memset(s1, 0x00, sizeof(s1));
	memset(s2, 0x00, sizeof(s2));
	rep(i, b) {
		s1[i] = a + 48;
	}
	rep(i, a) {
		s2[i] = b + 48;
	}
	int m = min(strlen(s1), strlen(s2));
	rep(i, m) {
		if (s2[i] < s1[i]) ans = s2;
	}
	cout << ans << endl;
}