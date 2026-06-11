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
	int A, B;
	cin >> A >> B;
	if (abs(A - B) % 2 == 1) cout << "IMPOSSIBLE" << endl;
	else cout << (A + B) / 2 << endl;
}