#include <bits/stdc++.h>
#include <unordered_set>
#include <random>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int board[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (board[i][j] == a) board[i][j] = 0;
	}
	
	bool yes = 0;
	for (int i = 0; i < 3; i++) {
		bool flag = 1;
		for (int j = 0; j < 3; j++) if (board[i][j] != 0) flag = 0;
		yes |= flag;

		flag = 1;
		for (int j = 0; j < 3; j++) if (board[j][i] != 0) flag = 0;
		yes |= flag;
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 0) yes = 1;
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 0) yes = 1;

	if (yes) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}