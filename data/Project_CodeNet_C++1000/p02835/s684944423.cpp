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
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		int A; cin >> A;
		sum += A;
	}
	if (sum <= 21) cout << "win" << endl;
	else cout << "bust" << endl;
}