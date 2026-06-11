#include "bits/stdc++.h"

#define REP(i,n) for(int i=0;i<n;++i)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=m-1;i>=n;--i)
#define ALL(v) v.begin(),v.end()
#define PB(a) push_back(a)
#define INF 1000000001
#define MOD 1000000007

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<int> p = { 2 };
	vector<bool> b(246913, false);
	b[2] = true;
	FOR(i, 3, 246913) {
		int flag = 1;
		REP(j,p.size()){
			if (i%p[j] == 0) flag = 0;
		}
		if (flag) {
			p.push_back(i);
			b[i] = true;
		}		
	}
	while (1) {
		int n;
		cin >> n;
		if (!n) break;
		int cnt = 0;
		FOR(i, n + 1, 2 * n + 1) {
			if (b[i]) cnt++;
		}cout << cnt << endl;

	}

	return 0; 
}