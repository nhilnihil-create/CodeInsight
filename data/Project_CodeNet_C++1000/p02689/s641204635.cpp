#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> h(n), c(n);  
    rep(i, n) cin >> h[i];  
    rep(i, m){
        int a, b;
        cin >> a >> b;
        if(h[a - 1] > h[b - 1]){
            c[a - 1]++;
            c[b - 1] -= 1000000;
        }else if(h[a - 1] == h[b - 1]){
            c[a - 1] -= 1000000;
            c[b - 1] -= 1000000;
        }        
        else{
            c[b - 1]++;
            c[a - 1] -= 1000000;
        }
    }
    int ans = 0;
    rep(i, n){
        if(c[i] >= 0){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}