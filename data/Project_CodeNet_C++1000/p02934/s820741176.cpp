/*
   Push yourself, because no one else is going to do it for you.
*/
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define set_zero(a) memset(a,0,sizeof(a));
#define ll long long int
#define PI 2 * acos(0.0)
#define MAX 1000000000000000000
#define in(a) scanf("%d",&a);
#define out(a) printf("%d",a);
#define INF 1000000 
#define M 1000000007
#define pi 3.14159265 
using namespace std; 
int main(){ 
   fast_io
   ll n;
   cin>>n;
   long double y = 0;
   ll a[n];
   for(ll i = 0;i<n;i++) cin>>a[i];
   for(ll i = 0;i<n;i++){
      long double sum = 1.0/(long double) (a[i]);
      y += sum; 
   }
   long double h = 1.0 / y;
   cout<<fixed<<setprecision(15)<<h<<endl;
   return 0;
} 