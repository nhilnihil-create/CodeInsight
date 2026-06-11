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

int main() {
	string S; cin >> S;
	int cnt = 0; int s_flg = 0;
	for (int ii = 0; ii < 3; ii++) {
		if (S[ii] == 'R') {
			if (s_flg == 1) {
				cnt = 1;
				s_flg = 0;
			} else {
				cnt++;
			}
		}
		else s_flg = 1;
	}
	cout << cnt << endl;
}