#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main() {
    ll n;
    cin >> n;
    map<int, int>mp;
    int m = 0;
    string ans = "YES";
    rep(i, n){
        int s;
        cin >> s;
        if(mp[s] == 0){
            mp[s] = 1;
        }else{
            ans = "NO";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
