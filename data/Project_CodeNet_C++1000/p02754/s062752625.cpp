#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<ll>
#define vii vector<pii>
#define pb push_back
#define mp  make_pair
#define all(v) (v).begin(), (v).end()

#define pb push_back
#define mp make_pair
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
ll INF = 1e6;

void solve()
{
    ll n, a, b;
    cin>>n>>a>>b;
    if(a==0)
    {
        cout<<0;
    }
    else
    {
        ll ans=0;
        if(n<=a)
            ans=n;
        else if(n>a &&n<a+b)
            ans=a;
        else
        {
            ans= a*(n/(a+b));
            n=n%(a+b);
            if(n<=a)
            ans+=n;
            //cout<<ans<<endl;
            if(n>a)
                ans+=a;
        }
        cout<<ans;
    }
}

 
int main()
{
    SPEED;
    ll t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
