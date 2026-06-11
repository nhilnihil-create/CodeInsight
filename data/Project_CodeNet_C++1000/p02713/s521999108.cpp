/*
 push yourself until you succeed
*/
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define set_zero(a) memset(a,0,sizeof(a));
#define ll long long int
#define PI 2 * acos(0.0)
#define MAX 10000000000000000
#define in(a) scanf("%d",&a);
#define out(a) printf("%d",a);
#define INF 1000000 
#define M 1000000007
#define pi 3.14159265 
using namespace std; 
int main(){ 
   fast_io
   ll ans = 0;
   ll k;
   cin>>k;
   for(ll i = 1;i<=k;i++){
       for(ll j = 1;j<=k;j++){
           for(ll m = 1;m<=k;m++){
               ll y = __gcd(i,j);
               ans += __gcd(y,m);
           }
       }
   }
   cout<<ans<<endl;
   return 0;
} 