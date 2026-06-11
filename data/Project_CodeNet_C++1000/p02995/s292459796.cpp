#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

ll gcd(ll a, ll b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}

int main() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	a--;
	ll cntd = b / d - a / d;
	ll cntc = b / c - a / c;
	ll g = lcm(c, d);
	ll cntcd = b / g - a / g;
	ll sum = cntd + cntc - cntcd;
	
	
	cout << b - a  - sum;
	return 0;
	

}