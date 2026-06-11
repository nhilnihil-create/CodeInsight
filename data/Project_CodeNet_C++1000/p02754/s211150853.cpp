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
	ll N, A, B; cin >> N >> A >> B;
	ll tmp = N / (A+B);
	ll tmp2 = N % (A+B);
	tmp = tmp * A;
	if (tmp2 <= A) {
		tmp += tmp2;
	} else {
		tmp += A;
	}
	cout << tmp << endl;
}