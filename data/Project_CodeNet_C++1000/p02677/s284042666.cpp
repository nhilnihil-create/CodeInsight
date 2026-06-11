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
double PI = 3.14159265358979323846;
int main()
{
	int A, B, H, M;
	cin >> A >> B >> H >> M;
	double degM = M * 6.0;
	double degH = H * 30.0 + M * 0.5;
	double deg = min(abs(degH - degM), 360 - abs(degH - degM));
	double ans = A * A + B * B - 2.0 * A * B * cos(deg * PI / 180);
	ans = pow(ans, 0.5);
	printf("%.10f\n",ans);
}