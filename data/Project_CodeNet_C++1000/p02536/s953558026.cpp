#include<bits/stdc++.h>

#define ff      first
#define ss      second
#define pb      push_back
#define ll      long long
#define MX      100005
#define inf     1000000
#define mod     1000000007
#define endl    "\n"

#define W(t)            while(t--)
#define all(v)          v.begin(),v.end()
#define ZERO(a)         memset(a,0,sizeof(a))
#define MINUS(a)        memset(a,-1,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS             ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int par[MX + 5], n, m;

int find(int v)
{
	if (par[v] < 0) return v;
	else return par[v] = find(par[v]);
}
int main()
{
	IOS

	int i,cnt=0;
	
	cin >> n >> m;

	rep(i, 1, n + 1) par[i] = -1;
	W(m)
	{
		int x, y; cin >> x >> y;
		int r1 = find(x);
		int r2 = find(y);

		if (r1 != r2) {
			par[r1] = r2;
		}
	}
	rep(i, 1, n + 1){
		if(par[i]==-1)
			cnt++;
	}

	cout << cnt-1 << endl;
}