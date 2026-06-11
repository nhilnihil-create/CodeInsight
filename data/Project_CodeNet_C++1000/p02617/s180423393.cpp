#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
     int i, j, k;
     int n;
     cin >> n;
     ll ans=0;
     for(i=1; i<=n; ++i){
          ll t=n-i+1;
          ans+=t*(t+1)/2;
     }
     for(i=0; i<n-1; ++i){
          int u, v;
          cin >> u >> v;
          if(u>v) swap(u, v);
          ans-=u*ll(n-v+1);
     }
     cout << ans << endl;
}
