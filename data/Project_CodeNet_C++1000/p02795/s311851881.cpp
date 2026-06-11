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

	int x, y, z;

	cin >> x >> y >> z;

	cout << (z % max(x, y) == 0 ? z / max(x, y) : z / max(x, y) + 1) << endl;

}