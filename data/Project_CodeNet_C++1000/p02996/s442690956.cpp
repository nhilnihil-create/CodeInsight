#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main() {

	int n;
	cin >> n;
	vector<pair<int, int>> work(n);
	rep(i, n)cin >> work[i].second >> work[i].first;

	sort(all(work));

	int time = 0;
	rep(i, n) {
		int a = work[i].second;
		int b = work[i].first;
		if (time + a <= b)time += a;
		else {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}