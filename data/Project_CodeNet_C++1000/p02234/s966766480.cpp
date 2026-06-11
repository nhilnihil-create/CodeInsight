#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<numeric>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

using namespace std;

struct matrix {
	int r, c;
	matrix(int r_ = 0, int c_ = 0) : r(r_), c(c_) {}
};

const int INF = 100000000;
vector<vector<int>> dp;

int mul(int r1, int rm, int c2) { return r1 * c2 * rm; }

int main() {
	int N;
	cin >> N;
	int R, C;
	vector<matrix> mats(N);	
	dp.assign(N+1, vector<int>(N+1, INF)); //[l, r)
	rep(i, N) {
		cin >> R >> C;
		mats[i] = matrix(R, C);
	}

	for(int len = 1; len < N+1; ++len) {
		for(int l = 0; l <= N-len; ++l) {
			int r = l + len;	
			if(l+1 == r) {
				dp[l][r] = 0;	
				continue;	
			}		
			for(int m = l+1; m < r; ++m) {	
				int r1 = mats[l].r;
				int rm = mats[m].r;
				int c2 = mats[r-1].c;
				dp[l][r] = min(dp[l][m] + dp[m][r] + mul(r1, rm, c2), dp[l][r]);
			}
		}
	}
	cout << dp[0][N] << endl;
	return 0;
}