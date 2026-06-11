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
    ll n , m , arr[2005] , brr[2005] , com[2005];

int main()
{
    ENGZ;
    cin>>n >>m ;
    for(int i=0 ; i<n ; i++)cin>>arr[i] ;
    for(int i=0 ; i<m ;i++)cin>>brr[i] ;

    for(int i=0 ; i<m ; i++)
    {
        ll tmp = 0 ;
        for(int j=0 ; j<n ; j++)
        {
            if(j>0)
            {
                if(arr[j] == brr[i])
                {
                    ll tt = tmp+ com[j] ;
                    com[j] += (tmp+1)%mod;
                    tmp = tt ;
                }
                else
                {
                    tmp+=com[j] ;
                }
                continue;
            }
            tmp += com[j] ;
            if(arr[j] == brr[i])
                com[j]++ ;
        }
    }
    ll ans = 0;
    for(int i=0 ; i<n ; i++)
    {
        ans+=com[i] ;
        ans %= mod ;
    }
    cout<<ans+1 <<endl ;
    return 0;
}
