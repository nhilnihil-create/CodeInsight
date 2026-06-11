#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define ex(k) (a*(b-n)+(a-b)*(k)-(k)*(k))
using namespace std;

int dsu[MAX];
int sz[MAX];

int search(int a)   {
    if(dsu[a]==a)   return a;
    return dsu[a]=search(dsu[a]);
}

void join(int a, int b)  {
    a = search(a);
    b = search(b);
    if(sz[a]>sz[b]) {
        dsu[b]=a;
        sz[a]+=sz[b];
    }
    else {
        dsu[a]=b;
        sz[b]+=sz[a];
    }
}

void solve()	{
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        dsu[i]=i;
        sz[i]=1;
    }
    while(m--)  {
        int x,y;
        cin >> x >> y;
        if(search(x)!=search(y))    join(x,y);
    }
    int ans=-1;
    for(int i=1; i<=n; i++) {
        ans=max(ans,sz[search(i)]);
    }
    cout << ans << endl;
}

int main()	
{
	int t=1;
	//cin >> t;
	for(int i=1; i<=t; i++)	{
		solve();
	}
	return 0;
}