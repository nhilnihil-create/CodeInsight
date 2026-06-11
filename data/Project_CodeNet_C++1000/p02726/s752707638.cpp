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
map<int,int> mp;

void dfs(int vis[],vector<int> v[],int curr,int depth,int now)
{
	vis[curr]=1;
	cout << now << " " << curr << " " << depth << endl;
	mp[depth]++;
	for(int i=0;i<v[curr].size();i++)
	{
		int j=v[curr][i];
		if(vis[j]==0 && j>curr)
		dfs(vis,v,j,depth+1,now);;
	}
}
int32_t main()
{
	int n,x,y;
	cin >> n >> x >> y;
	
	
	vector<int> v;
	int hash[n+1]={0};
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int r=j-i;
			int s=abs(x-i)+1+abs(y-j);
			//cout << i << " " << j << " " <<  x << " " << y << endl; 
			hash[min(r,s)]++;
		}
	}
	for(int i=1;i<=n-1;i++)
	cout << hash[i] << endl;
}


