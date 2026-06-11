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

ll calc(ll h) {
	if (h == 1) return 1;
	return 1 + 2 * calc(h / 2);
}
int main() 
{
	ll H;
	cin >> H;
	cout << calc(H) << endl;
}
