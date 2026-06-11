#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
using namespace std;

int main(){
    ll n,k; cin >> n >> k;
    vector<ll> a(n),f(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> f[i];
    sort(all(a));
    sort(all(f));
    reverse(all(f));
    
    ll l=0; ll r=1000000000000;
    while(r!=l){
        ll ce=(l+r)/2;
        bool ok=true;
        ll tmp=0;
        rep(i,n){
            if(a[i]*f[i]>ce) tmp+=((a[i]*f[i]-ce)+f[i]-1)/f[i];
            if(tmp>k){
                ok=false;
                break;
            }
        }
        if(ok) r=ce;
        else l=ce+1;
    }
    cout << r << endl;
return 0;
}

//rate1379