#include<bits/stdc++.h>
#define n 500000
#define mem(arr) memset(arr, 0, sizeof(arr))
using namespace std;
typedef long long lli;
typedef double llf;
typedef pair<int, int> P;
void solve();
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int times = 1;
//	cin >> times;
	for(int i=0; i<times; i++)
	{
		solve();
		cout << '\n';
	}
	return 0;
}

int a, b, c, d, e, f, g, h;
int arr[n + 50], arr1[n + 50], arr2[n + 50];

//type here

void solve()
{
	lli a, b; cin >> a >> b;
	lli pre[a + 50] = {0};
	for(int i=1; i<=a; i++)
	{
		lli tmp; cin >> tmp;
		pre[i] = pre[i - 1] + tmp;
	}
	lli left = 0, ans = 0;
	map<lli, lli> M;
	M[0] = 1;
	for(int i=1; i<=a; i++)
	{
		if(i >= b)
		{
			M[(pre[left] - left + b) % b] --;
			left ++;
		}
		ans += M[(pre[i] - i + b) % b];
		M[(pre[i] - i + b) % b] ++;
//		cout << ans << '\n';
	}
	cout << ans << '\n';
}