#include<iostream>
#include<algorithm>
#define REP(i,n) for(int i = 0;i < n ; i++)

typedef long long ll;

using namespace std;

bool pri1[2000000];
int pri2[2000000];
ll n ,ans;

void seg(int n)
{
	int p = 0;
	for(int i = 0;i <= n;i++)pri1[i] = true;
	pri1[0] = pri1[1] = false;
	for(int i = 2;i <= n;i++)
	{
		if(pri1[i])
		{
			pri1[p++] = i;
			for(int j = 2 * i;j <= n;j += i)pri1[j] = false;
			
		}
	}
}
			
			

int main()
{
	for(;;)
	{
		n = 0;
		ans = 0;
		cin >> n;
		if(n == 0)break;
		seg(2*n+1);
		for(int i = n+1;i<=2*n;i++)if(pri1[i])
		{
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}