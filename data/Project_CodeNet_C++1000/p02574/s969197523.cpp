#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define shalaby ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cerr.tie(0);

using namespace std;

inline int D()
{
    int t;
    scanf("%d",&t);
    return t;
}
inline ll llD()
{
    ll t;
    scanf("%lld",&t);
    return t;
}
ll mod=1e9+7;
const int OO=-1e6;
int xt[4]= {1,0,0,-1};
int yt[4]= {0,1,-1,0};
////////////////////////////////////////////////////////////////////////////////////

const int N = 1e6+1;
ll greatestPF[N];

int mem[100005][3],a[200005],b[105],n,m,k,frq[1000005];
bool valid(int x,int y)
{
    return x>-1 && y>-1 && x<n && y<m;
}
void init()
{
    memset(mem,-1,sizeof mem);
}
int sieve[N];
int main()
{

    sieve[0]= sieve[1] = 1;
	for (int i = 2; i < N; i++)
	{
		for (int j = i; j < N; j+=i)
		{
			if (sieve[j] == 0)sieve[j] = i;
			sieve[j] = min(i, sieve[j]);
		}
	}
    int T=1;
///   T=D();
    while(T-->0)
    {

        cin>>n;
        int g = 0;
	for (int i = 0; i < n; i++)cin >> a[i], g = __gcd(g, a[i]);
	for (int i = 0; i < n; i++)
	{
		while(a[i] != 1)
		{
			int cur = sieve[a[i]];
			frq[ cur ]++;
			while(a[i] % cur == 0)a[i]/=cur;
		}
	}
	int mx = 0;
	for (int i = 2; i < N; i++)mx = max(mx, frq[i]);
	///cout<<mx<<endl;
	if (mx <= 1)
	{
		cout <<"pairwise coprime\n";
	}else
	{
		if (g == 1)
		{
			cout <<"setwise coprime\n";
		}else
		cout <<"not coprime\n";
	}



    }
}
