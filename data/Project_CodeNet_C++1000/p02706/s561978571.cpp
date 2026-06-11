#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define pb            push_back
#define x             first
#define y             second
#define sz(v)         (int)v.size()
#define all(x)        (x).begin(),(x).end()
#define PI            3.14159265358979
#define N             200005

int solve(){
    int n,m; cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        int t; cin>>t;
        n-=t;
    }
    cout<<max(-1ll,n);
    return 0;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}