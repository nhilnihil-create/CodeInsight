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
     ll x[n] , y[n],xl[n],yl[n];
     ll maxx=-INF,minx=INF,maxy=-INF,miny=INF;
     for(int i=0;i<n;i++){
          cin >> x[i] >> y[i];
          xl[i] = x[i] + y[i] ;
          yl[i] = x[i] - y[i] ;

     }

     for(int i=0;i<n;i++){
          maxx = max(maxx,xl[i]);
          minx = min(minx,xl[i]);
          maxy = max(maxy,yl[i]);
          miny = min(miny,yl[i]);
     }
     
     ans = max(maxx-minx,maxy-miny);
     cout << ans << endl;



}