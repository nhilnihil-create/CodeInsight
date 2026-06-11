#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <functional>
#include <queue>
#include <cmath>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define rep1(i,n) for(int i=1;i<=(int)n;++i)

int N, K;

int Sum[200010];
map<int,int> counter;

int f(int a)
{
	a += K * (int)1e9;
	return a % K;
}

signed main()
{
	cin >> N >> K;

	int ans = 0;

	rep1(i, N) {
		cin >> Sum[i];
		Sum[i] += Sum[i-1];
		Sum[i] %= K;
	}

	counter[Sum[0] - 0]++;

	rep1(i, N) {
		if (i - K >= 0) counter[f(Sum[i - K] - (i - K))]--;
		ans += counter[f(Sum[i] - i)];
		counter[f(Sum[i] - i)]++;
	}

	cout << ans << endl;
}
