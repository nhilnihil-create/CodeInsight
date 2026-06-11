#include <bits/stdc++.h>

#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lowbit(x) (x & -x)
typedef long long ll;
using namespace std;
const int MAX = 0x7ffffff;
int t;

void slove()
{
	double n , m;
	cin >> n >> m;
	m = m * 100;
	m += 0.00001;
	ll x = n , y = m;
	cout << (x * y) / 100 << endl;
}
int main()
{
	SIS;
	slove();
}