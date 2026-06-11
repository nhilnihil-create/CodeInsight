#include <bits/stdc++.h>

#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lowbit(x) (x & -x)
#define PI 3.14159265358979323846264338327950L
typedef long long ll;
typedef long double ld;
using namespace std;
const int MAX = 0x7ffffff;
int t;
void slove()
{
	int a , b , h , m;
	cin >> a >> b >> h >> m;
	ld rad = PI * 2 * ((ld)h / 12.0 + ((ld)m / 60.0) / 12.0 - (ld)m / 60.0);
	ld rsq = (ld)(a*a + b*b) - (ld)(2*a*b)*cosl(rad);

	printf("%20.20Lf\n", sqrtl(rsq));
}
int main()
{
	SIS;
	slove();
}