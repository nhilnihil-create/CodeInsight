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
vector<ll> printDivisors(ll n) 
{ 
    vector<ll> v; 
    vector<ll> f;
    for (ll i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
  
            if (n / i == i)  
                f.push_back(i); 
            else { 
                f.push_back(i); 
  
                v.push_back(n / i); 
            } 
        } 
    } 
    for (ll i = v.size() - 1; i >= 0; i--){
       f.push_back(v[i]);
    }
  return f;
} 
int main(){ 
   fast_io
   ll n;
   cin>>n;
   vector<ll> v = printDivisors(n);
   ll dis;
   for(ll i = 0;i<v.size();i++){
      ll y = n / v[i];
      ll h = ( v[i]  - 1 ) + (y - 1);
      dis = min(dis,h);
   }
   cout<<dis<<endl;
   return 0; 
}  