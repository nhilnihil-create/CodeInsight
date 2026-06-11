#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    ll k;
    cin >> s >> k;
    ll n = s.size();
    if (n == 1){
        cout << k/2 << endl;
        return 0;
    }

    ll a = 0;
    for (ll i = 0; i < n; i++){
        if (s[0] == s[i]){
            a++;
        }
        else{
            break;
        }
    }

    if (a == n){
        cout << k*n/2 << endl;
        return 0;
    }

    ll b = 0;
    for (ll i = n-1; i >= 0; i--){
        if (s[n-1] == s[i]){
            b++;
        }
        else{
            break;
        }
    }

    ll d = 0;
    ll c = 1;
    for (ll i = a; i < n-b; i++){
        if (s[i] == s[i+1]){
            c++;
        }
        else{
            d += c/2;
            c = 1;
        }
    }
    d += c/2;

    ll ans = 0;

    if (s[0] == s[n-1]){
        ans += a/2;
        ans += b/2;
        ans += (a+b)/2 * (k-1);
        ans += d*k;
    }
    else{
        ans = ((a/2)+(b/2)+d)*k;
    }
    
    cout << ans << endl;


}