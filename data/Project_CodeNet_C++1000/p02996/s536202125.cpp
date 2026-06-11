#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i] >> b[i];
    }
    vector<pair<ll, ll>> w(n);
    for (ll i = 0;i < n;i++){
        w[i].first = b[i];
        w[i].second = a[i];
    }
    sort(w.begin(), w.end());

    ll shimekiri = 0;
    ll now = 0;
    bool x = true;

    for (ll i = 0; i < n; i++){
        shimekiri = w[i].first;
        now += w[i].second;
        if (shimekiri < now){
            x = false;
            break;
        }
    }

    if (x){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}