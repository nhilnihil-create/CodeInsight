#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> temp;
ll n, m, x, y;
vector<pair<ll,vector<ll>>> books;
bool poss = false;
ll res = 1000000000;

void solve(ll c, ll z) {
    if (c>=n) {
        bool ok = true;
        for (auto i : temp) if (i<x) ok = false;
        if (ok) {
            poss = true;
            res = min(res,z);
        }
        return;
    }
    z+=books[c].first;
    for (ll i=0; i<m; i++) {
        temp[i]+=books[c].second[i];
    }
    solve(c+1,z);
    z-=books[c].first;
    for (ll i=0; i<m; i++) {
        temp[i]-=books[c].second[i];
    }
    solve(c+1,z);
    return;
}

int main() {
    cin >> n >> m >> x;
    vector<ll> tempp;
    for (ll i=0; i<n; i++) {
        books.push_back(make_pair(ll(0),tempp));
    }
    for (ll i=0; i<n; i++) {
        cin >> y;
        books[i].first = y;
        for (ll j=0; j<m; j++) {
            cin >> y;
            books[i].second.push_back(y);
        }
    }
    for (ll i=0; i<m; i++) temp.push_back(0);
    solve(0,0);
    if (!poss) cout << -1;
    else cout << res;
    return 0;
}