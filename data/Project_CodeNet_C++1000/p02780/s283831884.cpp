#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n,k;cin>>n>>k;
    
    vi a(n);
    rep(i,n)cin>>a[i];
    
    vi l(n+1,0),r(n,0);
    
    for(int i=1; i<=n; i++){
        l[i] = l[i-1]+a[i-1];
    }
    
    for(int i=1; i<n; i++){
        r[i] = r[i-1]+a[n-i];
    }
    
    int ans = 0;
    
    for(int i=0; i<=n-k; i++){
        ans = max(ans, l[n]- l[i] - r[n-k-i]);
    }
    
    //cout << (ans+k)/2.0 << endl;
    printf("%.10lf\n", (ans+k)/2.0);
    return 0;
}
