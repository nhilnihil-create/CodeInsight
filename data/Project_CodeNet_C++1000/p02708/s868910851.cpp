#include<bits/stdc++.h>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#define endl  "\n"
#define ll long long
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cin.exceptions(cin.failbit);cout.tie(NULL);
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if ((n % i == 0) || (n % (i + 2) == 0))
            return false;
    }
    return true;
}
int mod=1e9+7;
int32_t main()
{
	int t=1;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		int pref[n+1]={0};
		int suf[n+1]={0};
		int a[n+1];
		for(int i=0;i<=n;i++)
		{
			a[i]=i;
			pref[i]=i;
			suf[n-i]=i;
		}
		
		for(int i=1;i<=n;i++)
		pref[i]+=pref[i-1];
		
		for(int i=n-1;i>=0;i--)
		{
			suf[n-i]+=suf[n-i-1];
		}
		
		int cnt=0;
		for(int i=k-1;i<=n;i++)
		{
			cnt+=(abs(suf[i]-pref[i])+1);
			cnt=cnt%mod;
		}
	
		cout << cnt;
	}
}


