#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i <= 999; i++) {
		string num = to_string(i);
		while (num.size() != 3) num = '0' + num;
		int p = 0;
		for (int j = 0; j < n; j++) {
			if (p < 3 && s[j] == num[p]) p++;
		}
		if (p == 3) ans++;
	}
	cout << ans << endl;
}