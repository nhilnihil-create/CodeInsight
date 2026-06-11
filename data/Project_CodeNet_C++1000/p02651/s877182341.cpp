#include <bits/stdc++.h>
/* Uncomment only if you are not using GNU compiler->
*/
#include <map>
#include <algorithm> 
#include <vector> 
#include <string.h> 
#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <chrono> 
#include <thread> 
#include <iomanip>
/**/ 
//define
#define rep(i,n)    for(int i=0;i<n;i++)
#define repu(i,k,n) for(int i=k;i<=n;i++)
#define repd(i,k,n) for(int i=k;i>=n;i--)
#define se second
#define fi first
#define pb push_back
#define mp make_pair
#define all(v)  v.begin(), v.end()

//typedef
typedef long long int ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::vector<int> vi;
typedef std::vector< pii > vii;
typedef std::vector< ll > vll;
typedef std::vector< std::pair < pii, int > > vpp;
 
const long long MOD = 1000000007;
const long long inf = 1e18;
 
using namespace std;

int t=0;

ll modpow(ll x,ll n){
    ll res=1;
    while(n>0){
        if(n&1) res=res*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return res;
}

ll power(ll x, ll n)
{
    ll res=1;
    while(n>0){
        if(n&1) res=res*x;
        x=x*x;
        n>>=1;
    }
    return res;
}

bool check(vll &b, ll x)
{
    rep(i,62)
    {
        if(((1LL<<i)&x)==0)
            continue;
        if(b[i]!=-1)
            x^=b[i];
        else
        {
            b[i]=x;
            return true;
        }
    }
    return false;
}

void solve()
{
    int n;
    cin>>n;
    vll v(n);
    rep(i,n)
    {
        cin>>v[i];
    }
    string s;
    cin>>s;
    vll b(62,-1);
    repd(i,n-1,0)
    {
        bool hi=check(b,v[i]);
        if(hi && s[i]=='1')
        {
            cout<<1<<endl;
            return;
        }
    }
    cout<<"0\n";
}
 
int main() {
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("hh.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1, tt=1;
    cin>>t;
    while(tt<=t)
    {
        // cout<<"Case #"<<tt<<": ";
        solve();
        tt++;
    } 
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}