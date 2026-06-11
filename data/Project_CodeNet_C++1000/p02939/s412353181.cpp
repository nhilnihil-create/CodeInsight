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
    string s ;
    cin>> s ;
    int a ,b , c;
    int ans = 0 ;
    a = b = c = 0 ;
    s = "."+s;
    for(int i=1 ; i<sz(s) ; i++)
    {
        if(s[i] != s[a])
        {
            a = i ;
            ans ++ ;
        }
        else if(i < sz(s)-1)
        {
            ans++ ;
            i++ ;
            a = 0;
        }
        else
        {
            break;
        }
    }

    cout<<ans <<endl ;

    return 0;
}
