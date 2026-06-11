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
   ll sieve[100006];
   set_zero(sieve);
   sieve[1] = 1;
   ll y = 100005;
   for(ll i = 2;i<=y;i++){
      if(sieve[i] == 0){
         if(i >= n){
            cout<<i<<endl;
            break;
         }
         for(ll j = i*2;j<=y; j += i){
            sieve[j] = 1;
         }
      }
   }
   return 0;
}