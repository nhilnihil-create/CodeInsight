// 7/6 バーチャル参加
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A + B + C >= 22) cout << "bust" << endl;
    else cout << "win" << endl;
}