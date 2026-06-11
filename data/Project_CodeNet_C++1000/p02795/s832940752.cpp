#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 * 2;

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	int div = max(h, w);
	cout << (n + div - 1) / div << endl;
}
