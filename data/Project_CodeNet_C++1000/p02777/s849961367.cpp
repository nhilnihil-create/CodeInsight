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
	string S, T; cin >> S >> T;
	int A, B; cin >> A >> B;
	string U; cin >> U;
	if (S == U) A--;
	if (T == U) B--;
	cout << A << " " << B << endl;
}