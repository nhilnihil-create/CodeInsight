#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll n, ans;
struct node{
	ll x, y;
}p[N];
bool cmp1(node a, node b)
{
	return a.x + a.y < b.x + b.y;
}
bool cmp2(node a, node b)
{
	return a.x - a.y < b.x - b.y;
}
bool cmp3(node a, node b)
{
	return a.y - a.x < b.y - b.x;
} 
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
    sort(p + 1, p + 1 + n, cmp1);
    ans = max(ans, p[n].x + p[n].y - p[1].x - p[1].y);
    sort(p + 1, p + 1 + n, cmp2);
    ans = max(ans, (p[n].x - p[n].y) - (p[1].x - p[1].y));
    sort(p + 1, p + 1 + n, cmp3);
    ans = max(ans, (p[n].y - p[n].x) - (p[1].y - p[1].x));
    cout << ans << endl;
	return 0;
}
