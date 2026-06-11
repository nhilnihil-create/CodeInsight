#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;
const int MOD = 1000000007;
 
int main(){
    int m; cin>>m;
    ll d[m],c[m];
    rep(i,m) cin>>d[i]>>c[i];
    ll S=0;
    ll res=0;

    rep(i,m){
         res+=c[i];
         S+=(d[i]*c[i]);
    }
    res--;
    res+=(S-1)/9;

    cout<<res<<endl;
   
}