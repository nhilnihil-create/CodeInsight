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

int R, C;

int count_senbei(vector<int> &senbei) {
	int res = 0;
	for(int i = 0; i < C; ++i) {	
		int cnt = __builtin_popcount(senbei[i]);
		res += max(cnt, R - cnt);
	}
	return res;
}

int main() {
	while(cin >> R >> C && R) {
		vector<int> init_senbei(C, 0);
		int tmp = 0;	
		for(int i = 0; i < R; ++i) {
			for(int j = 0; j < C; ++j) {
				cin >> tmp;
				init_senbei[j] |= tmp * (1<<i);
			}	
		}
		int ans = 0;	
		vector<int> senbei = init_senbei;
		for(int bit = 0; bit < (1<<R); ++bit) {
			senbei = init_senbei;
			for(int x = 0; x < C; ++x) {
				senbei[x] = bit ^ init_senbei[x];
			}	
			ans = max(ans, count_senbei(senbei));
		}
		cout << ans << endl;
	}
	return 0;
}