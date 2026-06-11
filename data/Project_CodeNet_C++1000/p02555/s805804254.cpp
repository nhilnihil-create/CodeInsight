#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;

ll move(ll n){
     ll a[n+10];
     a[0] = 1;
     a[1] = 0;
     a[2] = 0;
     a[3] = 1;

     for(int i=4;i<=n;i++){
          a[i] = (a[i-1]+a[i-3])%MOD;
     }
     return a[n];
}

int main (){
     ll n;     cin >> n;
     ans = move(n);
     cout << ans%MOD << endl;
}