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
const int MOD = 998244353;
const ll INF = 1000000000000000000;


int main()
{
	string S;
	cin >> S;
	int ans = 0;
	for (int i = 0; i < S.size() / 2; i++) {
		int j = S.size() - 1 - i;
		if (S[i] != S[j]) ans++;
	}
	cout << ans << endl;
}