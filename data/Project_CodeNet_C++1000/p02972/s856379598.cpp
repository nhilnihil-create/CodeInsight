#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {
	
	int n;
	cin >> n;
	V<bool> a(n);
	rep(i, n) {
		int k;
		cin >> k;
		if (k)a[i] = true;
	}

	V<bool> ball(n);
	int m = 0;

	rep(i, n) {

		int k = n - i;
		int kk = 2 * k;

		int cnt = 0;

		while (kk <= n) {
			if (ball[kk - 1])cnt++;
			kk += k;
		}

		cnt %= 2;
		if (cnt == a[n - 1 - i])continue;
		ball[n - 1 - i]=true;
		m++;

	}

	cout << m << endl;
	rep(i, n)if (ball[i])cout << i + 1 << " ";
	cout << endl;

}