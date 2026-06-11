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
	int N, K, S;
	cin >> N >> K >> S;
	for (int i = 0; i < K; i++) {
		if (i != 0) cout << " ";
		cout << S;
	}
	for (int i = K; i < N; i++) {
		cout << " ";
		if (S == 1) cout << 2;
		else cout << S - 1;
	}
	cout << endl;
}