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
		set<int> s;
		int x=n-1;
		for(int i=1;i<=sqrt(x);i++)
		{
			if(x%i==0)
			{
				if(i>1)
				s.insert(i);
				if(x>i)
				s.insert(x/i);
			}
		}
		for(int i=1;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				if(i>1)
				{
					int temp=n;
					while(temp%i==0)
					{
						temp=temp/i;
					}
					if(temp>i)
					{
						if(temp%i==1)
						s.insert(i);
					}
					else
					{
						if(temp==1)
						s.insert(i);
					}
				}
				else if(n>i)
				{
					int temp=n;
					int div=n/i;
					while(temp%div==0)
					temp=temp/div;
					
					if(temp>div)
					{
						if(temp%div==1)
						s.insert(div);
					}
					else
					{
						if(temp==1)
						s.insert(div);
					}
					
				}
			}
		}
		cout << s.size();
	}
}


