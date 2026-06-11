#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	int N;
	cin >> N;
	int v[110];
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);
	double ans = (v[0] + v[1]) / 2.0;
	for (int i = 2; i < N; i++) {
		ans = (ans + v[i]) / 2.0;
	}
	printf("%.6f\n", ans);
}