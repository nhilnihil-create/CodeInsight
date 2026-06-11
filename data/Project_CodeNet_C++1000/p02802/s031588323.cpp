#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 100000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)
#define MAX_T 100000
int AC[MAX_T+1];
int WA[MAX_T+1];
int main() {
	int N, M; cin >> N >> M;
	int p; string s;
	rep(i, M) {
		cin >> p >> s;
		if (AC[p] == 1) continue;
		if (s == "WA") WA[p]++;
		else AC[p]++;
	}
	int A = 0, W = 0;
	rep(i, MAX_T+1) {
		if (AC[i] == 1) {
			A++; W += WA[i];
		}
	}
	cout << A << " " << W << endl;
}