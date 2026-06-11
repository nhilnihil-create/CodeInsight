/*
My heart’s beating faster
I know what I’m after
 
I’ve been standing here my whole life
Everything I’ve seen twice
Now it’s time I realized
It’s spinning back around now
On this road I’m crawlin’
Save me 'cause I’m fallin’
Now I can’t seem to breathe right
'Cause I keep runnin' runnin' runnin' runnin'
Runnin' runnin' runnin' runnin'
Runnin' from my heart
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
#define nt _int128
#define fir first
#define sec second
#define slow_as_snail ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define debugged cout<<"debugged\n";
#define inf 0x3f3f3f3f
#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end() 
 
const ll mod = 1000000007;
#define mx 10000005
const ll mxi = 100005;

// vector<ll> gr[mxi];

int main()
{
    slow_as_snail;
    vector<ll> gr[mxi];
    ll n,m;
    cin>>n>>m;
    ll ht[mxi];
    for(int i=0;i<n;i++)
    {
        cin>>ht[i];
    }
    for(int i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        x--,y--;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        ll fl = 1;
        for(auto it : gr[i])
        {
            if(ht[it]>=ht[i])
            {
                fl = 0;
                break;
            }
        }
        if(fl)
        {
            ans++;
        }
    }
    cout<<ans;
}