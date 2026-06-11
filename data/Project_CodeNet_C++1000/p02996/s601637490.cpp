#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        p[i] = make_pair(b, a);
    }

    sort(p.begin(), p.end());

    ll cnt = 0;

    bool b = true;
    rep(i, n) {
        cnt += p[i].second;

        if(cnt>p[i].first){
            b = false;
            break;
        }
    }

    if(b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}