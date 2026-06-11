#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX/2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, m;
	cin >> n >> m;

	priority_queue<P,vector<P>,greater<P>> p;

	rep(i, n) {
		int a, b;
		cin >> a >> b;
		p.push(make_pair(a, b));
	}

	priority_queue<int,vi,less<int>> pq;
	int ans = 0;

	rep1(i, m) {
		if (p.size() > 0)while (p.top().first <= i) {
			pq.push(p.top().second);
			p.pop();
			if (p.size() == 0)break;
		}
		if (pq.size() > 0){ans += pq.top();pq.pop();}
	}

	cout << ans << endl;

}