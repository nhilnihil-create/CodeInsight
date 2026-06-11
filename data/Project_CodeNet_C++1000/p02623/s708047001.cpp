#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n+1, 0);
    vector<ll> b(m+1, 0);
    
    rep2(i,1, n+1){
        cin >> a[i];
        if(i!=0)a[i]+=a[i-1];
        
    }
    
    int lim_b = m;
    rep2(i,1, m+1){
        cin >> b[i];
        if(i!=0)b[i]+=b[i-1];
        if(b[i]>k)lim_b = (i<lim_b)? i : lim_b;
    }
    
    ll ans = 0;
    rep(i, n+1){
        if(a[i]>k)break;
        for(int j=lim_b; j>=0; j--){
            if(a[i]+b[j]<=k){
                ans = (i+j)>ans? (i+j) : ans;
                lim_b = j;
                break;
            }
        }
    }
    
    cout << ans << endl;
}