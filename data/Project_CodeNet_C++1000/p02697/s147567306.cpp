#pragma GCC optimize("O3")
#pragma G++ optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mst(a, b) memset((a), (b), sizeof(a))
#define mp(a, b) make_pair(a, b)
#define pi acos(-1)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
const ll INF = 0x3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int maxn = 2e5 + 7;
const int maxm = 1e5 + 7;
const int mod = 192600817;
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    IO;
    int n,m;
	cin>>n>>m;
	for(int i=1;i<=(m+1)/2;++i)
		cout<<i<<" "<<m+2-i<<endl;
	for(int i=1;i<=m/2;++i)
		cout<<m+1+i<<" "<<2*m+2-i<<endl;
    return 0;
}