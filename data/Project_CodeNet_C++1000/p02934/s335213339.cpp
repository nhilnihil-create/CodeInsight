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
	int N;
	cin >> N;
	double ans = 0.0;
	for (int i = 0; i < N; i++) {
		double A;
		cin >> A;
		ans += 1.0 / A;
	}
	printf("%.10f\n", 1.0 / ans);
}