#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll                 long long
#define mod                1000000007
#define pb                 push_back
#define vecsort(v)         sort(v.begin(),v.end())
#define lcm(x,y)           (x/__gcd(x,y))*y
#define forn(i,n)          for(i = 0 ; i < n ; i++)
#define deb(x)             cout << #x << " " << x << endl;
#define T(t)               cout << "Case " << t <<": ";
#define scan(v)            for(int i = 0; i<n; i++){ll x;cin>>x;v.pb(x);}
#define fast_cin           ios_base::sync_with_stdio(false);cin.tie(NULL);




int main() {



     ll x , k , d;
     cin >> x >> k >> d;
     x = abs( x );
     if( x/d >= k ){
         cout << x - (d * k ) << endl;
         return 0 ;
     }
     ll t = x / d;
     x -= t * d;
     k -= t;
     if( k % 2 == 0 ){
         cout << abs(x) << endl;
     }
     else{
         cout << min(abs(x-d),abs(x+d)) << endl;
     }









    return 0;

}