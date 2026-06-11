#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;

int main (){
     ll n;     cin >> n;
     ll a[n];
     for(int i=0;i<n;i++){
          cin >> a[i];
     }

     for(int i=1;i<n;i++){
          if(a[i] - a[i-1] < 0){
               ans += ( a[i-1] - a[i] );
               a[i] += a[i-1] - a[i] ;
          }
     }
     cout << ans << endl;
}