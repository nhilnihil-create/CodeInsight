#include <bits/stdc++.h>

#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lowbit(x) (x & -x)
#define PI 3.14159265358979323846264338327950L
typedef long long ll;
using namespace std;
const int MAX = 0x7ffffff;
int t;

void slove()
{
	int n;cin >> n;
	cout << (ll)n * (n - 1) / 2 << endl;
}
int main()
{
	SIS;
	slove();
}