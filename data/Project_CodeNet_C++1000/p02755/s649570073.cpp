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
    ll a, b;
    cin>>a>>b;
    for(ll i=b*10; i<b*10+10;i++)
    {
        if(i*8/100==a)
        {
            cout<<i;
            exit(0);
        }
    }
    cout<<-1;
}

 
int main()
{
    SPEED;
    ll t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
