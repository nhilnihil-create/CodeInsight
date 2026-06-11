#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=1e5+5;

ll ara[MX], csm[MX];

int main(){
     ll i, j, k;
     ll n;
     cin >> n;
     for(i=0; i<=n; ++i) cin >> ara[i];
     for(i=n; i>=0; --i) csm[i]=csm[i+1]+ara[i];
     ll cur=1, ans=1;
     for(i=0; i<=n; ++i){
          cur-=ara[i];
          if(cur<0){
               puts("-1");
               return 0;
          }
          cur*=2LL;
          cur=min(cur, csm[i+1]);
          ans+=cur;
     }
     cout << ans << endl;
}
