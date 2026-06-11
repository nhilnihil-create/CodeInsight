#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N = 1e5;
LL a[N+1];
LL bck[N+1];
LL f[N+1];
LL solve(LL a[], int n)
{
	if(a[0] > 0) //and depth >= 1
		return (a[0]==1 && n==0) ? 1 : -1;
	bck[n] = a[n];
	for(int i = n-1; i >= 0; i--)
		bck[i] = bck[i+1]+a[i];

	f[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		f[i] = min(2LL*(f[i-1]-a[i-1]),bck[i]);
		if(f[i] < a[i])
			return -1;
	}

	LL ans = 0;
	for(int i = 0; i <= n; i++)
		ans += f[i];
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	for(int i = 0; i <= n; i++)
		cin >> a[i];
	cout<<solve(a,n)<<endl;

	cout<<flush;
	return 0;
}