#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1LL << 60)
#define rep(i, n) for(int i=0; i<(n); ++i)

int main()
{
	int N; cin >> N;
	vector<pair<int,int>> rb(N);
	rep(i, N) {
		int x, l; cin >> x >> l;
		rb[i].first = x + l;
		rb[i].second = x - l;
	}
	auto cmpr = [](pair<int, int> a, pair<int, int> b)
	{
		if (a.first != b.first) return a.first < b.first;
		return a.second > b.second;
	};
	sort(rb.begin(), rb.end(), cmpr);
	int now = 0 - INF;
	int cnt = 0;
	rep(i, N) {
		if (rb[i].second >= now) {
			++cnt;
			now = rb[i].first;
		}
	}
	cout << cnt << endl;
	return 0;
}
