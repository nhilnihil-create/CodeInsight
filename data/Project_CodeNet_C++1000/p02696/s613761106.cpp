/*
   Push yourself, because no one else is going to do it for you.
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
using namespace std;
int main(){ 
   fast_io
   ll a,b,n; 
   cin>>a>>b>>n;
   if(n >= b){
      ll x = b-1;
      ll ans = (a*x)/b;
      cout<<ans<<endl;
   }
   else{
      ll x = n;
      ll ans = (a*n)/b;
      cout<<ans<<endl;
   }
   return 0; 
}  