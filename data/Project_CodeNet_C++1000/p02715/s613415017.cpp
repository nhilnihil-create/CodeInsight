#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll  unsigned long long
#define ull unsigned long long
#define IO ios::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define main() int main()
#define ff1(i,n) for(int i=1;i<=n;++i)
#define ff0(i,n) for(int i=0;i<n;++i)
#define pi acos(-1.0)
#define ms(a, x) memset(a, x, sizeof(a))
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
#define binarycount __builtin_popcount(x)
#define tr t[root]
#define lson t[root << 1]
#define rson t[root << 1 | 1]
#define fir first
#define sec second
#define debug(x) cout<<x<<'\n'
#define sa(a) scanf("%d", &a)
#define sab(a, b) scanf("%d%d", &a, &b)
#define pa(a) printf("%d",a)
#define pab(a,b) printf("%d%d",a,b)
#define pii pair<int,int>
using namespace std;

#define maxn 1000005
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-8;
ll gcd(ll a, ll b) {return b==0?a:gcd(b, a%b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}
ll powmod(ll a,ll b){
    ll ans = 1, pow = a%mod;
    while(b) { if(b&1) ans = (ans*pow)%mod; pow = (pow*pow)%mod; b >>= 1; }
    return ans;
}
bool run(int year=NULL)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}
struct node{
	int x,y;
}a[20000];
int n;
ll k,ans[maxn],anss=0;
main(){
	IO;
	cin>>n>>k;
	for(ll x=k;x>=1;x--){
		ll y=k/x;
		ll cap=powmod(y,n);
		for(ll i=x+x;i<=k;i+=x)
		{
			cap=(cap-ans[i]+mod)%mod;
		}
		ans[x]=cap;
		anss=(anss+cap*x)%mod;
	}
	cout<<anss<<endl;
}