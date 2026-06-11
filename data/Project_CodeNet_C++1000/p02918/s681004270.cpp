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
	int N, K;
	string S;
	cin >> N >> K >> S;
	int ans = 0;
	for (int i = 0; i < N - 1; i++) {
		if (S[i] == S[i + 1]) ans++;
	}
	cout << min(N - 1, ans + 2 * K) << endl;
}
