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
		set<int> s,s2;
		for(int i=1;i<=9;i++)
		s.insert(i);
		
		while(s2.size()<n)
		{
			s2.insert((*s.begin()));
			int x=(*s.begin());
			//cout << x << " ";
			s.erase(s.begin());
			int temp=x%10;
			
			if(temp==0)
			{
				s.insert(x*10);
				s.insert(x*10+1);
			}
			else if(temp==9)
			{
				s.insert(x*10+8);
				s.insert(x*10+9);
			}
			else
			{
				s.insert(x*10+temp-1);
				s.insert(x*10+temp);
				s.insert(x*10+temp+1);
			}
		}
		auto it=s2.end();
		it--;
		cout << (*it);
	}
}


