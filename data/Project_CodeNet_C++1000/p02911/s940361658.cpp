#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v(n, 0);
    rep(i, q) {
        int a;
        cin >> a;
        v[a-1]++;
    }
    for(auto &x : v) {
        cout << ((q - x) < k ? "Yes" : "No") << endl;
    }
}