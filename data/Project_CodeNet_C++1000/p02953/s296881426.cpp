#include<bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    int n;
    cin >> n;
    vi h(n);
    rep(i, n) cin >> h[i];
    int tmpmax = 0;
    bool isok = true;
    rep(i, n){
        tmpmax = max(tmpmax, h[i]);
        if(h[i]<tmpmax-1) isok = false;
    }

    if(isok) cout << "Yes";
    else cout << "No";
}