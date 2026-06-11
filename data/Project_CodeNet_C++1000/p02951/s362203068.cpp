#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("O3")
#define lll __int128_t
#define ll long long int
#define FOR(i,a,b) for(ll (i)=(a);i<(ll)(b);i++)
#define FORr(i,a,b) for(ll(i)=(a);i>(ll)(b);i--)
#define rep(i,n) FOR(i,0,n)
#define rep1(i,n) FOR(i,1,n)
#define outi(a) printf("%lld\n",(a))
#define case(i) cout << "Case " << i << ": ";
#define pb push_back
#define in(n) ll n = read();
#define show(arr) for(auto a : arr) cout << a << " "; cout << endl;
#define inp(arr, n) ll arr[n] ; rep(i,n) arr[i] = read();
#define mp make_pair
#define f first 
#define s second 
#define mod 1000000007
#define modu(a) if(a>=mod) a-=mod;
#define test int tt = read(); rep(i,tt) solve(i+1);
using namespace std;
inline ll read()
{
    ll x=0; static ll p; p=1; static char c; c=getchar();
    while (!isdigit(c)) { if (c=='-') p=-1; c=getchar(); }
    while ( isdigit(c)) { x=(x<<1)+(x<<3)+(c-48); c=getchar(); }
    x*=p;
    return x;
}
int solve(int tt);
int main()
{
    //system("clear");
   // freopen("input.txt", "r", stdin);
    in(a) in(b) in(c)
    ll remain = a- b;
    cout << max(c-remain, 0LL) << endl;
}