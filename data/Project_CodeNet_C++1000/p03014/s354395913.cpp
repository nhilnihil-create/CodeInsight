#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
using namespace std;
using ll = long long;

int main() {
	int H, W; cin >> H >> W;
	vector<vector<int>> vec(H, vi(W));

	for (int i = 0; i < H; i++) {
		string s; cin >> s;
		for (int j = 0; j < W; j++) {
			if (s[j] == '.') vec[i][j] = 1;
			else vec[i][j] = 0;
		}
	}

	vector<vector<int>> temp1(H, vi(W));
	for (int i = 0; i < H; i++) {
		temp1[i][0] = vec[i][0];
		for (int j = 1; j < W; j++) {
			temp1[i][j] = temp1[i][j - 1] + vec[i][j];
			if (vec[i][j] == 0) temp1[i][j] = 0;
		}
	}

	vector<vector<int>> temp2(H, vi(W));
	for (int i = 0; i < H; i++) {
		temp2[i][W - 1] = vec[i][W - 1];
		for (int j = W - 2; j > -1; j--) {
			temp2[i][j] = temp2[i][j + 1] + vec[i][j];
			if (vec[i][j] == 0) temp2[i][j] = 0;
		}
	}

	vvi temp3(H, vi(W));
	for (int j = 0; j < W; j++) {
		temp3[0][j] = vec[0][j];
		for (int i = 1; i < H; i++) {
			temp3[i][j] = temp3[i - 1][j] + vec[i][j];
			if (vec[i][j] == 0) temp3[i][j] = 0;
		}
	}

	vvi temp4(H, vi(W));
	for (int j = 0; j < W; j++) {
		temp4[H - 1][j] = vec[H - 1][j];
		for (int i = H - 2; i > -1; i--) {
			temp4[i][j] = temp4[i + 1][j] + vec[i][j];
			if (vec[i][j] == 0) temp4[i][j] = 0;
		}
	}


	int ans = 0;
	rep(i, H) rep(j, W) ans = max(ans, temp1[i][j] + temp2[i][j] + temp3[i][j] + temp4[i][j] - 3);

	cout << ans << endl;
}