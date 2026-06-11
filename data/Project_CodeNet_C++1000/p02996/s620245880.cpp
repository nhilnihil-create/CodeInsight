#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t N;
	cin >> N;
	// 配列の作成
	vector<pair<int64_t, int64_t>> dat(N);
	for (int64_t i = 0; i < N; i++) {
    	cin >> dat[i].second >> dat[i].first;	
    }
	sort(dat.begin(), dat.end());
	// 0がB,1がA 昇順
	int64_t t = 0;
	for (int64_t i = 0; i < N; i++) {
		t += dat[i].second;
		if (dat[i].first < t) {
			cout << "No" << endl;
			break;
		}
		if ( i == N-1) {
			cout << "Yes" << endl;
		}
	}
	
}