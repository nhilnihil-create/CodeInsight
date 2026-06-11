#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef int64_t ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    //bool a[n + 1] = {false};
    ll gap = m, fs = 1, bs = n, fe, be, flag = 1;
    for(ll i = 0; i < m; i++) {
        if(flag) {
            flag = 0;
            fe = fs + gap;
            cout << fs << " " << fe << "\n";
            fs++;
        }
        else {
            flag = 1;
            be = bs - gap;
            cout << be << " " << bs << "\n";
            bs--;
        }
        gap--;
    }
}    

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);
    ll t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}