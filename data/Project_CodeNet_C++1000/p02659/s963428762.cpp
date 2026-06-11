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



     ll a , b ;
     double t ;
     cin >> a >> t;
     b = 100LL * ( t + 0.001 );
    // cout << 100ll*t << " " << 10LL*0.001 << endl;
     cout << a*b/100 << endl;








    return 0;

}