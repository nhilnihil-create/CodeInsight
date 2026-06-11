#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll N, A, B;
    cin >> N;
    map<ll, ll> mp;
    rep(i,N) {
        cin >> A >> B;
        mp[B] += A;
    }
    ll sum = 0;
    string ans = "Yes";
    for (auto x : mp) {
        sum += x.second;
        if (sum > x.first) ans = "No";
    }
    cout << ans << endl;
}
