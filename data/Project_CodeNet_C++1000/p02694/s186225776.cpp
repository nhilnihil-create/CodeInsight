#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846264338327950L

ll x;

void solve(){

    cin >> x;

    int ans = 0;
    ll cur = 100;
    while(x > cur){
        ans++;
        cur += cur/100;
    }

    cout << ans << endl;
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}