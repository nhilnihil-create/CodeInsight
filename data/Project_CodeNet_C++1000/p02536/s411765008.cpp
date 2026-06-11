#include<bits/stdc++.h>
using namespace std;

/* MIGHT BE OF USE


#define si(x)	scanf("%d",&x)
#define pi(x)	printf("%d\n",x)

typedef pair<int, int>	pii;
typedef vector<int>		vi;
typedef vector<pii>		vpii;
*/


#define fo(i,a,b) for(i=a;i<b;i++)
#define ll long long
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define sl(x)	scanf("%lld",&x)
#define pl(x)	printf("%lld\n",x)
#define ss(s)	cin>>s
#define ps(s)	cout<<s
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back

typedef pair<ll, ll>	pl;
typedef vector<ll>		vl;
typedef vector<pl>		vpl;
typedef vector<string>	vs;

ll gcd(ll a , ll b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}


vl v[100001];
bool visited[100001]={0};

void dfs(ll att){
    visited[att]=1;
    for(ll i=0;i<v[att].size();i++){
        ll num = v[att][i];
        if(visited[num]) continue;
        visited[num]=1;
        dfs(num);
    }

}

void solve()
{
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ll i, j, n, m;
    cin>>n>>m;
    ll a,b;
    fo(i,0,m){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    ll ans=0;

    fo(i,1,n+1){
        if(visited[i]) continue;
        dfs(i);
        ans++;
    }
    cout<<ans-1;

}



int main()
{

    ll t = 1;
    //sl(t);
    while(t--)
    {
        solve();
    }

    return 0;
}




