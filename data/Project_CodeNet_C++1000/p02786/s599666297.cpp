#include<bits/stdc++.h>
#define ll unsigned long long
#define ld long double
#define all(v) v.begin(),v.end()
#define sz size()
#define mp make_pair
#define pb push_back
#define rep(p,a,b) for(ll p=a ; p<b ; p++)
#define rap(p,a,b) for(ll p=a ; p<=b ; p++)
#define per(p,a,b) for(ll p=a ; p>=b ; p--)
#define F first
#define S second
using namespace std;

typedef vector <ll> vll;
typedef vector <ld> vld;
typedef pair< ll ,ll > pll;


map<ll,ll> m;

ll solve(ll n)
{
    if(m[n])return m[n];
    m[n] = 2*solve(n/2)+1;
    return m[n];
}

int main()
{
    ll t,i,j,k,ans,n;

    //cin>>t;
    t=1;
    while(t--)
    {
        m[1] = 1;
        rep(p,2,1e3)m[p] = 2*m[p/2]+1;

        cin>>n;
        cout<<solve(n);
    }
    
    return 0;
}