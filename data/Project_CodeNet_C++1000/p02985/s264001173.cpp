#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (ll I = (A); I <= (B); I++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(ll i=0;i<n;i++)
#define sz(a) ll((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array);
//bool can;
const ll N=1000005;
std::vector<ll> visited;
ll ans;
ll k;
const ll MOD=1000000007;
ll fact[N], invfact[N];

ll Power(ll base , ll e)
{
    if(e == 0) return 1;
    ll ans = base; e--;
    while(e)
	{
        if(e & 1) ans = (((ans%MOD) * (base%MOD)) %MOD+MOD)%MOD;
        base = (((base%MOD) * (base%MOD)) %MOD+MOD)%MOD;
        e >>= 1;
	}
	return (ans+MOD) %MOD;
}


ll gcd(ll a,ll b)
{
if(a==0) return b;
else return gcd(a%b,b);
}

    ll modinv(ll k)
    {
        return Power(k, MOD-2);
    }

    void precompute()
    {
        fact[0]=fact[1]=1;
        for(ll i=2;i<N;i++)
        {
            fact[i]=fact[i-1]*i;
            fact[i]%=MOD;
        }
        invfact[N-1]=modinv(fact[N-1]);
        for(ll i=N-2;i>=0;i--)
        {
            invfact[i]=invfact[i+1]*(i+1);
            invfact[i]%=MOD;
        }
    }

    ll nCr(ll x, ll y)
    {
        if(y>x)
            return 0;
        ll num=fact[x];
        num*=invfact[y];
        num%=MOD;
        num*=invfact[x-y];
        num%=MOD;
        return num;
    }


std::vector<ll> adj[100005];
void fu(ll node,ll res){
	ll cnt=0;
	if(res==0) cnt=1;
	else cnt=2;
	ans=((ans%MOD)*(nCr(k-res,1)%MOD))%MOD;
	visited[node]=1;
	for(auto kk:adj[node]){
		if(!visited[kk]) fu(kk,cnt++);
	}

}

int main(){
	ll n;
	IOS
	
	cin>>n>>k;
	ans=1;
	//can=true;
	precompute();
	visited.resize(n+1,0);
	
	ll aa,bb;
	
	
	fo(i,n-1){
		cin>>aa>>bb;
		adj[aa].pb(bb);
		adj[bb].pb(aa);


	}
	fu(1,0);
	cout<<ans<<endl;


}