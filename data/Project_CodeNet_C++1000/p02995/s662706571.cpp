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

ll gcd(ll a, ll b)
{
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	else return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return a * (b / gcd(a, b));
}

int main()
{
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	ll ans = B / C + B / D - B / lcm(C, D);
	ll num = (A - 1) / C + (A - 1) / D - (A - 1) / lcm(C, D);
	cout << (B - A + 1) - ans + num << endl;
}
