#include<iostream>
#include<vector>
#include<string>
#include <queue>
#include<map>
#include<set>
#include <cstring>
using namespace std;
#define ll long long int


int main()
{
    int n , m , k ;
    cin>>n>>m>>k ;
    vector<ll>  r(n , 0) , c(m , 0) ;

    set<pair<ll ,ll>> st ;
    for(ll i = 0 ; i < k ; i++)
    {
        ll a , b ;
        cin>>a>>b ;
        a-- ;
        b-- ;
        st.insert({a , b}) ;
        r[a]++ ;
        c[b]++ ;

    }
    ll maxr = -1 , maxc = -1 ;
    for(ll i = 0  ; i < n ; i++)
    {
        if(r[i] > maxr)
        {
            maxr = r[i] ;

        }
    }

    vector<ll> vr , vc ;
      for(ll i = 0  ; i < n ; i++)
    {
        if(r[i] == maxr)
        {
            vr.push_back(i) ;

        }
    }
     for(ll i = 0  ; i < m ; i++)
    {

        if(c[i] > maxc)
        {

            maxc = c[i] ;

        }
    }
     for(ll i = 0  ; i < m ; i++)
    {

        if(c[i] == maxc)
        {

            vc.push_back(i) ;

        }
    }

    ll ans = 0 ;
    ll n1 = vr.size() , m1 = vc.size() ;
    for(ll i = 0 ; i < n1 ; i++)
    {
        for(ll j = 0 ; j < m1 ; j++)
        {

                if(st.find({vr[i] , vc[j]}) == st.end()){
                  ans = max(ans , r[vr[i]] + c[vc[j]]) ;
                  break ;
                }
                else
                  ans = max(ans , r[vr[i]] + c[vc[j]] - 1) ;


        }
    }

    cout<<ans ;
}
