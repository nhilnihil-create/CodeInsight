#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
const ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s[0] == 'W' || s[2*n-1] == 'W') {
        cout << "0" << endl;
        return 0;
    } 
    vector<bool> flag(2*n,false);
    bool a = false;
    for(int i = 1; i < 2*n; i++){
        if(s[i] != s[i-1]){
            flag[i] = a;
        } else {
            flag[i] = !a;
            a = !a;
        }
    }
    ll l[2*n] = {};
    l[0] = 1;
    for(int i = 1; i < 2*n; i++){
        if(flag[i]) l[i] = l[i-1];
        else l[i] = l[i-1] + 1;
    }
    if(l[2*n-1] != n){
        cout << "0" << endl;
        return 0;
    }
    ll ans = 1;
    ll count = 0;
    rep(i,2*n){
        if(flag[i]) {
            ans = ans*(l[i]-count) % mod;
            count++;
        }
    }
    for(ll i = 1; i <= n; i++) ans = (ans*i) % mod;
    cout << ans << endl;
    return 0;
}