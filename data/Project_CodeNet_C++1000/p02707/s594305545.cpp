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

vector<int> v[N];

int solve(){
    int n; cin>>n;
    for(int i=2; i<=n; i++){
        int t; cin>>t;
        v[t].push_back(i);
    }
    for (int i = 0; i < n; ++i)
    {
        cout<<v[i+1].size()<<"\n";
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