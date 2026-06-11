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
	int p[30];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i];
	int ans = 0;
	for (int i = 1; i < N - 1; i++) {
		if ((p[i - 1] < p[i] && p[i] < p[i + 1]) || (p[i - 1] > p[i] && p[i] > p[i + 1])) ans++;
	}
	cout << ans << endl;
}
