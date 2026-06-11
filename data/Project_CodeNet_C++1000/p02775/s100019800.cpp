#include <bits/stdc++.h>

using namespace std;
#define sz(a) int(a.size())
#define ll  long long
#define mod int(1e9+7)
#define endl '\n'
#define ENGZ ios::sync_with_stdio(0);ios_base::sync_with_stdio(0);cin.tie(0) , cout.tie(0) ;
#define pi (acos(-1))
#define S second
#define F first
ll fp(ll n , ll p )
{
    if(p==0)
        return 1;
    if(p==1)
        return n ;
    ll res = fp(n,p/2) ;
    res=((res)*(res)) ;
    if(p%2)
        res=(res*n) ;
    return res ;
}

int main()
{
    ENGZ;
    string s;
    cin>>s ;
    ll ans = 0 , f = 0;
    for(int i=sz(s)-1 ; i>=0 ; i--)
    {
        ll dig = s[i]-'0';
        if(f)dig++;
        f = 0 ;
        if(dig > 5)
        {
            ans += 10 - dig ;
            f = 1 ;
        }
        else if(dig == 5 && i>0 && s[i-1]-'0' > 4)
        {
            ans += 10 - dig ;
            f = 1 ;

        }
        else
        {
            ans += dig ;
        }
    }
    if(f)ans++ ;
    cout<<ans <<endl ;
    return 0;
}
