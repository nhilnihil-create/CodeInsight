#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define line cout<<"\n"
#define ci std ::cin
#define co std ::cout
#define sf scanf
#define sff(n,m) scanf("%d%d",&n,&m)
#define pf printf
#define p_line printf("\n")
#define cas(n) printf("Case %d: ",n++)
#define task return
#define loop(x,n)  for(int x = 0 ; x < n ; x++)
#define constloop(x,a,n) for(int x = a ; x < n ; x++)
#define revloop(x,a,n)  for(int x = a ; x >= n ; x--)
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi acos(-1)
#define mx 10000000
/*ll P[mx+5],cnt=1;
bool nP[mx+5];
void sieve(void)
{
    P[0]=2;
    nP[0]=true;
    nP[1]=true;
    for(ll i=3 ; i<=mx ; i+=2)
    {
        if(nP[i]==true)
            continue;
        for(ll j=i+i ; j<=mx ; j+=i)
            nP[j]=true;
        P[cnt++]=i;
    }
}*/
ll modd=1e9+7;
ll bigmod(ll base,ll pow)
{
	if(pow==0)
		return 1;
	if(pow==1)
		return base%modd;
	ll ans=bigmod(base,pow/2);
	ans=(ans*ans)%modd;
	if(pow%2==1)
		ans=(ans*base)%modd;
	return ans;
}
void solve()
{
    //Code here
 	ll n;
 	ci>>n;
 	ll ans1=1,ans2=1,ans3=1;
 	ll a=10,b=9,c=8;
 	ans1=bigmod(a,n);
 	ans2=bigmod(b,n);
 	ans3=bigmod(c,n);
 	ll ans=((((ans1-ans2+modd)%modd-ans2+modd)%modd)+ans3)%modd;
 	co<<ans;
 	line;
}
int main()
{
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	/*ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
	solve();
	return 0;
}