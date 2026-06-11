#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    bool ans = true;
    int n; cin >> n;
    int h[n];
    rep(i,n) cin >> h[i];
    int ma = 1;
    rep(i,n){
        ma = max(ma,h[i]);
        if(ma >= h[i] + 2) ans = false;
    }
    cout << ((ans)? "Yes" : "No") << endl;
    return 0;
}