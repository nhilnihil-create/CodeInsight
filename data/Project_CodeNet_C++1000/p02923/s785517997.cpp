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

int32_t main()
{
	int t=1;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++)
		cin >> a[i];
		
		int mx=0;
		int cnt=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]<=a[i-1])
			{
				cnt++;
			}
			else
			{
				mx=max(mx,cnt);
				cnt=0;
			}
		}
		mx=max(mx,cnt);
		
		cout << mx;
	}
}


