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

// freopen ("myfile.txt","w",stdout);



int main()
{
    ENGZ;

    double w,h,x,y ;
    cin>>w >>h  >> x >> y ;
    long double ans = (w*h) ;
    ans/=2 ;
    bool f = 0 ;
    if(x == w/2.0 && y == h/2.0)f=1 ;
    cout<<setprecision(9) <<fixed ;
    cout<<ans <<"  " <<f <<endl ;

    return 0;
}
