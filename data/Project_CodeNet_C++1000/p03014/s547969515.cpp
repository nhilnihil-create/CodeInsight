#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;
int MOD = 1000000007;
int PI = 3.14159265358979323846;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define For(i,s,n) for (int i=s;i<(int)(n);i++)
#define vi vector<int>
#define vii vector< vector<int> >
#define vs vector<string>
#define All(c) (c).begin(), (c).end()
#define Print(x) cout<<(x)<<"\n"

int H, W;
vs S(2010);
int DURL[2010][2010][4];

int main() {

	cin >> H >> W;
	rep(i, H) cin >> S[i];

	rep(i, W) rep(j, H) {
		if (j == 0 && S[j][i] == '.') DURL[j][i][0] = 1;
		else if (S[j][i] == '.') DURL[j][i][0] = DURL[j - 1][i][0] + 1;
	}
	rep(i, W) rrep(j, H) {
		if (j == H - 1 && S[j][i] == '.') DURL[j][i][1] = 1;
		else if (S[j][i] == '.') DURL[j][i][1] = DURL[j + 1][i][1] + 1;
	}

	rep(i, H) rep(j, W) {
		if (j == 0 && S[i][j] == '.') DURL[i][j][2] = 1;
		else if (S[i][j] == '.') DURL[i][j][2] = DURL[i][j - 1][2] + 1;
	}
	rep(i, H) rrep(j, W) {
		if (j == W - 1 && S[i][j] == '.') DURL[i][j][3] = 1;
		else if (S[i][j] == '.') DURL[i][j][3] = DURL[i][j + 1][3] + 1;
	}

	int ans = 0;
	int cnt = 0;
	rep(i, H) rep(j, W) {
		cnt = DURL[i][j][0] + DURL[i][j][1] + DURL[i][j][2] + DURL[i][j][3] - 3;
		chmax(ans, cnt);
	}
	cout << ans << endl;


}