#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

vector<int> to [100005];
int fact[100005];
int ifact[100005];
ll ans = 1;
int n,k;



int PowMod(int n,int m)
{
    ll temp;
    if (m == 0)
    {
        return 1;
    }
    if (m % 2 == 0)
    {
        temp = (ll)PowMod(n, m / 2);
        temp = (ll)temp * (ll)temp % (ll)MOD;
        return (int)temp;
    }
    temp =(ll)n * (ll)PowMod(n, m - 1) % (ll)MOD;
    return (int)temp;
}

int inv_num(int num)
{
    return PowMod(num, MOD - 2);
}


void factorial()
{
    fact[0] = 1;
    ifact[0] = 1;
    ll temp;
    for (int i = 1; i < 100005; i++)
    {
        temp = (ll)fact[i - 1] * (ll)i % (ll)MOD;
        fact[i] = (int)temp;
        ifact[i] = inv_num(fact[i]);
    }
}

int perm(int n, int a)
{
    if(a>n) return 0;
    int X = fact[n];
    int Y = ifact[n-a];
    ll temp;
    temp =  (ll)X * (ll)Y % (ll)MOD;
    return (int)temp;
}

void dfs(int v, int p = -1)
{
    for (auto u : to[v])
    {
        if(u == p) continue;
        dfs(u,v);
    }
    int nk = (p == -1) ? k:k-2;
    int c  = (p==-1) ? sz(to[v])+1: sz(to[v])-1;
    ans *= (ll)perm(nk,c);
    ans %= MOD;
}



int main()
{
    
    cin >> n >> k;
    //to.resize(n);
    rep(i,n-1)
    {
        int a,b;
        cin >> a  >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    factorial();
    dfs(0);
    //cout << PowMod(2,MOD-1) << endl;

    //cout << perm(5,2) << endl;
    //cout << inv_num(2) << endl;
    
    cout  << ans%MOD << endl;

}