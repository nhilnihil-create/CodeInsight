#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define set_zero(a) memset(a,0,sizeof(a));
#define ll long long
#define PI 2 * acos(0.0)
#define MAX 1000000000
#define INF 1000000 
#define M 1000000007
using namespace std;
int main(){
   fast_io
   ll n;
   cin>>n;
   ll a[n];
   for(ll i = 0;i<n;i++){
      cin>>a[i];
   }
   ll x = 1;
   ll ans = 0;
   for(ll i = 0;i<n;i++){
       if(a[i] == x){
          ans++;
          x++;
       }
   }
   if(ans == 0){
      ans = n+1;
   }
   cout<<n-ans<<endl;
   return 0;
}