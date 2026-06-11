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
	fast;
	int t=1;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		
		vector<int> v[3];
		for(int i=0;i<n;i++)
		{
			if(s[i]=='R')
			v[0].push_back(i);
			else if(s[i]=='G')
			v[1].push_back(i);
			else
			v[2].push_back(i);
		}
		int cnt=0;
		for(int i=0;i<n-2;i++)
		{
			if(s[i]=='R')
			{
				auto it=lower_bound(v[1].begin(),v[1].end(),i+1);
				
				for(it;it!=v[1].end();it++)
				{
					auto itr=lower_bound(v[2].begin(),v[2].end(),(*it)+1);
					for(itr;itr!=v[2].end();itr++)
					if(it!=v[1].end() && itr!=v[2].end() && ((*it)-i)!=((*itr)-(*it)))
					cnt++;
				}
					it=lower_bound(v[2].begin(),v[2].end(),i+1);
				for(it;it!=v[2].end();it++)
				{
					auto itr=lower_bound(v[1].begin(),v[1].end(),(*it)+1);	
					for(itr;itr!=v[1].end();itr++)
					if(it!=v[2].end() && itr!=v[1].end() && ((*it)-i)!=((*itr)-(*it)))
					cnt++;
				}
			}
			else if(s[i]=='G')
			{
				auto it=lower_bound(v[0].begin(),v[0].end(),i+1);
				for(it;it!=v[0].end();it++)
				{
					auto itr=lower_bound(v[2].begin(),v[2].end(),(*it)+1);
					for(itr;itr!=v[2].end();itr++)
					if(it!=v[0].end() && itr!=v[2].end() && ((*it)-i)!=((*itr)-(*it)))
					cnt++;
				}
				it=lower_bound(v[2].begin(),v[2].end(),i+1);
				for(it;it!=v[2].end();it++)
				{
					auto itr=lower_bound(v[0].begin(),v[0].end(),(*it)+1);
					for(itr;itr!=v[0].end();itr++)
					if(it!=v[2].end() && itr!=v[0].end() && ((*it)-i)!=((*itr)-(*it)))
					cnt++;
				}
			}
			else
			{
				auto it=lower_bound(v[0].begin(),v[0].end(),i+1);
				for(it;it!=v[0].end();it++)
				{
					auto itr=lower_bound(v[1].begin(),v[1].end(),(*it)+1);
					for(itr;itr!=v[1].end();itr++)
					if(it!=v[0].end() && itr!=v[1].end() && ((*it)-i)!=((*itr)-(*it)))
					cnt++;
				}
				it=lower_bound(v[1].begin(),v[1].end(),i+1);
				for(it;it!=v[1].end();it++)
				{
					auto itr=lower_bound(v[0].begin(),v[0].end(),(*it)+1);
					for(itr;itr!=v[0].end();itr++)
					if(it!=v[1].end() && itr!=v[0].end() && ((*it)-i)!=((*itr)-(*it)))
					cnt++;
				}
			}
		}
		cout << cnt;
	}
}


