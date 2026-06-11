#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define inf 1000000000
#define mod 1000000007
using namespace std;
template <class T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <class T> void chmin(T &x,T y){x=x<y?x:y;return;}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

int n,a[15];

void dfs(int p,int maxn)
{
	if(p>n)
	{
		for(int i=1;i<=n;i++)
			cout<<char(a[i]+'a');
		cout<<endl;
		return;
	}
	for(int i=0;i<=maxn;i++)
	{
		a[p]=i;
		dfs(p+1,maxn);
	}
	a[p]=maxn+1;
	dfs(p+1,maxn+1);
	return;
}

int main()
{
	cin>>n;
	dfs(1,-1);
	return 0;
}