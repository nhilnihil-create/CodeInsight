//lunchtime june Increasing and Decreasing
//<<  <  ,
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <algorithm>
#include <math.h>
#include <string>
#define pi 3.1415926535897932384626
#include <cmath>
#define test(t) while(t--)
#define MOD 1000000007
#define ll  long long int

#define in  cin>>
#define out cout<<
#define en "\n"
#define sp " "
#define pb push_back
#define fast()  ios_base::sync_with_stdio(false);cin.tie(0);
#define double long double

using namespace std;
ll form(ll n){
return (n*(n+1))/2;
}
ll exponent(ll base, ll power){
   ll res = 1;
  ll m = 1000000007;
   while(power){
    if(power&1)
        res = (res*base)%m;
    base= (base*base)%m;
    power=power>>1;
   }
return res;}
bool count_one(ll n){
    ll cnt = 0;
    while(n>0){
            cnt+=1;
       n= n&(n-1);

    }
    if(cnt>1)
        return true;
    return false;
}


void solve()
{   ll l,r,d;
    in l>>r>>d;
    while(l%d!=0){
        l+=1;
        if(l%d==0)
            break;

    }
    while(r%d!=0){
        r-=1;
        if(r%d==0)
            break;
    }
        ll n=(r-l)/d;
        out n+1<<en;
}




int main(){ fast()
             //freopen("input.txt","r",stdin);
             //freopen("output.txt","w",stdout);
             ll t=1;
            //cin>>t;
            test(t){
            solve();
            }
return 0;}
