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
    int a,b,c,k; cin>>a>>b>>c>>k;
    if(k<=a+b){
        cout<<min(k,a);
    }
    else{
        cout<<a-(k-(a+b));
    }
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