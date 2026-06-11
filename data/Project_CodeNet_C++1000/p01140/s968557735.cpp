#include <bits/stdc++.h>

using namespace std;

#define for_(i,a,b) for(int i=a;i<b;i++)
#define minit(a,b) memset(a,b,sizeof(a));
#define ALL(a) a.begin(),a.end()

int N, M;
int h[2000], w[2000];

void solve() {
	vector<int> H, W;
	for_(k,0,N) {
		for_(i,0,N-k) {
			int sum = 0;
			for_(j,i,i+k+1) sum += h[j];
			H.push_back(sum);
		}
	}
	for_(k,0,M) {
		for_(i,0,M-k) {
			int sum = 0;
			for_(j,i,i+k+1) sum += w[j];
			W.push_back(sum);
		}
	}
	sort(ALL(H)); sort(ALL(W));
	
	int ans = 0;
	int hsize = (int)H.size();
	for_(i,0,hsize) {
		int hi = H[i];		
		int numh = upper_bound(ALL(H),hi) - lower_bound(ALL(H),hi);
		int numw = upper_bound(ALL(W),hi) - lower_bound(ALL(W),hi);
		ans += numh * numw;
		i += numh - 1;
	}
	
	cout << ans << endl;
}

int main() {
	while (cin >> N >> M, N) {
		for_(i,0,N) cin >> h[i];
		for_(i,0,M) cin >> w[i];
		solve();
	}
	
	return 0;
}