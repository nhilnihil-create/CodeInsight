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
vector<int> v[200050];
int32_t main()
{
	int t=1;
	while(t--)
	{
		int n,k,c;
		cin >> n >> k >> c;
		string str;
		cin >> str;
		vector<int> v,v2;
		int i=0,cnt=0;
		while(i<n && cnt<k)
		{
			if(str[i]=='o')
			{
				v.push_back(i);
				i+=c;
				cnt++;
			}
			i++;
		}
		i=n-1,cnt=k-1;
		while(i>=0 && cnt>=0)
		{
			if(str[i]=='o')
			{
				v2.push_back(i);
				i-=c;
				cnt--;
			}
			i--;
	
		}
		reverse(v2.begin(),v2.end());
		for(int i=0;i<k;i++)
		{
			//cout << v[i] << " " <<  v2[i] << endl;
			if(v[i]==v2[i])
			cout << v[i]+1 << endl;
		}
	}
	
}


