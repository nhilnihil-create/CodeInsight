#include <bits/stdc++.h>

using namespace std;
#define sz(a) int(a.size())
#define ll  long long int
#define mod (long long)(1e9+7)
#define endl '\n'
#define ENGZ ios::sync_with_stdio(0);ios_base::sync_with_stdio(0);cin.tie(0) , cout.tie(0) ;
#define pi (acos(-1))
#define F first
#define S second

ll fp(ll n , ll p )
{
    if(p==0)
        return 1;
    if(p==1)
        return n ;
    ll res = fp(n,p/2);
    res=((res)*(res)) ;
    if(p%2)
        res=(res*n) ;
    return res ;
}

ll n , m , a,  b , c , cnt = 0 , cost = 0;
map<ll,ll> mp;
int main()
{
    ENGZ;
    cin>>n >>m ;
    mp[0] = 0 ;
    for(int i=0 ; i<m ; i++)
    {
        cin>>a >>b ;
        cnt = 0 ;
        for(int i=0 ; i<b ; i++)
        {
            cin>>c ;
            cnt+= fp(2,c-1); // to change digit of mask ..
        }
        for(auto i:mp)
        {
            ll mask = i.F | cnt;
            if(mp.count(mask))mp[mask] = min(mp[mask],i.S + a);
            else mp[mask] = i.S + a;
        }
    }
    ll a5er_box = fp(2,n) -1;
    for(auto i:mp)cerr<<i.F <<" " <<i.S <<endl ;
    cerr<<"---------------------------" <<endl ;
    if(mp.count(a5er_box))cout<<mp[a5er_box] <<endl;
    else cout<<-1 <<endl ;
    return 0;
}
