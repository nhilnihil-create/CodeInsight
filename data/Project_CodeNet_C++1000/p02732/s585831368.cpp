#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;

int64_t f(int64_t n){
    return n*(n-1)/2;
}

int main(){
    /*
    cin.tie(0);
    ios::sync_with_stdio(false);
    */
    int n;
    cin>>n;
    
    vector<int64_t> a(n);
    rep(i,n)cin>>a[i], a[i]--;
    
    vector<int64_t> m(n,0);
    rep(i,n)m[a[i]]++;
    
    int64_t ans = 0;
    rep(i,n)ans += f(m[i]);
    
    rep(i,n){
        //cout << ans -f(m[a[i]]) + f(m[a[i]]-1) << endl;
        printf("%lld\n", ans -f(m[a[i]]) + f(m[a[i]]-1));
    }
    
    return 0;
}