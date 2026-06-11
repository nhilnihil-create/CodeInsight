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
//setprecision(15)

int main() {
	int A, B; cin >> A >> B;
	int tmp = A * 100 / 8;
	int tmp2 = B * 100 / 10;
	int mi = min(tmp, tmp2);
	int ma = max(tmp, tmp2);
	for (int ii = mi-1; ii <= ma+1; ii++) {
		if ((ii*8/100 == A) && (ii*10/100 == B)) {
			cout << ii << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
}