#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<pair<int,int>> w(N);
	rep(i,N) {
		int x, y;
		cin >> x >> y;
		w[i] = make_pair(y, x);
	}
	sort(w.begin(), w.end());
	ll tot = 0;
	rep(i,N) {
		tot += w[i].second;
		if (tot > w[i].first) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
