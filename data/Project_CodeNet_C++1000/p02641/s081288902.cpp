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

ll a[2000005];

int main() {
     
       #ifndef ONLINE_JUDGE
       //freopen("read.txt","r",stdin);
      // freopen("write.txt","w",stdout);
       #endif

       ll x, n;
       cin >> x >> n ;
       set < ll > s;
       ll mx = 0;
       for( int i = 0 ; i < n ; i++ ){
              cin >> a[i];
              s.insert(a[i]);
       }

       if( n == 0 ){
              cout << x << endl;
              return 0;
       }

       ll mn = 1e9;
       ll ans ;
       for( int i = 0 ; i <= 105 ; i++ ){
             if( abs(i - x ) < mn && !s.count(i)){
                    mn = abs(x-i);
                    ans = i ;
                   
             }
       }
       cout << ans << endl;

     

       
       
      

       




       return 0;

}