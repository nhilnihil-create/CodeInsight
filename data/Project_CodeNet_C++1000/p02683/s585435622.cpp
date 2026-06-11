#include <bits/stdc++.h>

#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lowbit(x) (x & -x)
#define PI 3.14159265358979323846264338327950L
typedef long long ll;
using namespace std;
const int MAX = 0x7ffffff;
const int N = 100;
int t;
ll a[N][N] , c[N] , sum[N];
void slove()
{
	int n , m , x;
	cin >> n >> m >> x;
	for(int i = 0;i < n;i ++)
	{
		cin >> c[i];
		for(int j = 0;j < m;j ++)
			cin >> a[i][j];
	}
	ll mincost = MAX;
	for(int op = 0;op <= (1 << n) - 1;op ++)
	{
		memset(sum , 0 ,sizeof sum);
		ll tmpcost = 0;
		bool flag = false;
		for(int i = 0;i < n;i ++)
		{
			if(((op >> i) & 1))
			{
				tmpcost += c[i];
				for(int j = 0;j < m;j ++)
					sum[j] += a[i][j];
			}
		}
		for(int i = 0;i < m;i ++){
			if(sum[i] < x){
				flag = true;break;
			}
		}
		if(!flag){
			mincost = min(mincost ,tmpcost);
		}
	}
	if(mincost == MAX)cout << -1 << endl;
	else cout << mincost << endl;	
}
int main()
{
	SIS;
	slove();
}