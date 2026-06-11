#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> l;
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        l.emplace_back(b, a);
    }
    sort(l.begin(), l.end());
    ll time = 0;
    bool ok = true;
    for(auto k : l){
        time += k.second;
        if(k.first < time){
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes": "No") << endl;
}