#include<bits/stdc++.h>
using namespace std;

// マクロ
#define rep(i,N) for(int i = 0; i < N; i++)
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define cou(x) cout << x << endl
#define y() cout << "Yes" << endl
#define n() cout << "No" << endl
#define Y() cout << "YES" << endl
#define N() cout << "NO" << endl
#define x2(x) x * x

// 型エイリアス
using lint = long long;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;

int main() {

	int N;

	cin >> N;

	vector<pair<string, int>> list(N);
	string name;
	int time;

	rep(i, N) {
		cin >> name >> time;
		list[i].first = name;
		list[i].second = time;
	}
	int sleeptime = 0;

	string X;
	cin >> X;

	rep(i, N) {
		if (list[i].first == X) {
			i++;
			for (; i < N; i++) {
				sleeptime += list[i].second;
			}
		}
	}
	cou(sleeptime);
}