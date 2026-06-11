#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define rep(i, n) for(int i=0; i<(n); ++i)

int main()
{
	int N; cin >> N;
	//連結数 = 頂点 - 辺
	ll v = 0;
	rep(i, N) v += (ll)(i + 1) * (N - i);	//N個からi個選ぶ選び方
	ll e = 0;
	rep(i, N - 1) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		e += (ll)a * (N - b + 1);	//頂点a, bが含まれる頂点の選び方
	}
	cout << v - e << endl;
	return 0;
}
