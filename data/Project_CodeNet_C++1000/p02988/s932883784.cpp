#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int N;
	cin >> N;
	vector<int> p(N);
	rep(i, N) cin >> p[i];
	int cnt = 0;
	for (int i = 1; i < N - 1; i++){
		if ((p[i - 1] < p[i] && p[i] <= p[i + 1]) || (p[i + 1] < p[i] && p[i] <= p[i - 1])){
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
