#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 * 2;

int main() {
	string s;
	cin >> s;
	rep(i, s.size()){
		cout << ((s[i] == '?') ? 'D' : s[i]);
	}
	cout << endl;
}
