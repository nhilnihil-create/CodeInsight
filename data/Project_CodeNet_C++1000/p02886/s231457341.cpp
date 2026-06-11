#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod  200003//1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)

int main(){
   ios_base::sync_with_stdio(false);
   ll n;
   cin>>n;
   ll a[n];
   for(ll &x : a){
      cin>>x;
   }
   ll ans=0;
   for(ll i=0;i<n;i++){
      for(ll j =i+1;j<n;j++){
         ans+=(a[i]*a[j]);
      }
   }
   cout<<ans;
   return 0;
}