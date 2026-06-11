#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define INF 2e9
#define IMAX 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long llong;

int main()
{
	int N;
	string S;
	cin >> N >> S;
	char sChar[N * 2 + 1];
	S.copy(sChar, N * 2);

	int sBW[N * 2];

	// 初期化＆奇数番目を反転
	REP(idx, N * 2) {
		if (sChar[idx] == 'B') {
			// Black
			sBW[idx] = 0;
		} else {
			// White
			sBW[idx] = 1;
		}
		if (idx % 2 != 0) {
			// 奇数番目のマス目は反転する
			sBW[idx] = 1 - sBW[idx];
		}
	}

	// B-W(L-R)の組み合わせ算出
	llong cnt = 1;
	int haveL = 0;
	REP(idx, N * 2) {
		if (sBW[idx] == 0) {
			// L個数足す
			++haveL;
		} else {
			// カウントにLの個数かける
			cnt = cnt * haveL % IMAX;
			// L個数引く
			--haveL;
		}
		if (haveL < 0) {
			// 負になったら解なし
			cout << "0" << endl;
			return 0;
		}

	}

	if (haveL != 0) {
		// B-Wの個数が合ってない時も解なし
		cout << "0" << endl;
		return 0;
	}

	// 最後に N! をかける
	FOR(idx, 1, N) {
		cnt = cnt * idx % IMAX;
	}

	cout << cnt << endl;
	return 0;
}
