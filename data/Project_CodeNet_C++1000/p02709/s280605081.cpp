// https://atcoder.jp/contests/abc163/tasks/abc163_e

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LLMAX (1ll << 60) - 1
#define INTMAX (1 << 30) - 1
#define MOD 1000000007 
#define NMAX 1000*100+1
 
#define numberOfSetBits(S) __builtin_popcount(S) // __builtin_popcountl(S) __builtin_popcountll(S)
#define MSET(x,y) memset(x,y,sizeof(x))
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define isOn(S, j) (S & (1 << j))
#define getBit(S, j) ((S & ( 1 << j )) >> j)
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define print(x)    for(auto it=x.begin();it!=x.end();it++) cout<<*it<<' '; cout<<endl;
#define printii(x)  for(auto it=x.begin();it!=x.end();it++) cout<<*it.F<<' '<<*it.S<<'\t';  cout<<endl;
#define printn(x)   for(auto it=x.begin();it!=x.end();it++) cout<<*it<<endl;
#define in(x,n)   for(int e=0;e<n;e++){int y;cin>>y;x.pb(y);}
 
#define vi vector<int>
#define vll vector<ll>
#define ii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<ii>
#define viii vector<pair<ii,int>>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mc(a,b,c) mp(mp(a,b),c)

int n=2001;
pair<int,ll> arr[2001];
ll dp[2001][2001];

bool desc(pair<int,ll> a,pair<int,ll> b)
{
    return (a.S>b.S);
}
ll solve(int l, int r)
{
    if(dp[l][r]!=-1)
        return dp[l][r];
    
    if(l==r)
        return 1ll*abs(arr[n].F-l)*arr[n].S;

    ll res= max(solve(l+1,r)+1ll*abs(arr[n-r+l].F - l)*arr[n-r+l].S,solve(l,r-1)+1ll*abs(arr[n-r+l].F - r)*arr[n-r+l].S);
    dp[l][r]=res;

    return res;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        arr[i]=mp(i,x);
    }
    sort(arr+1,arr+n+1,desc);
    MSET(dp,-1);
    cout<<solve(1,n);
    

    return 0;
}
