#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;
const int bits = 60;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int64 x = 0;
    vector<int64> val(n);

    for (int i = 0; i < n; ++i){
        cin >> val[i];
        x ^= val[i];
    }

    vector<int> order(bits);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int u, int v){
        int bu = x >> u & 1;
        int bv = x >> v & 1;
        if (bu != bv)
            return bu < bv;
        return u > v;
    });

    vector<int64> gauss(bits);

    for (auto v : val) {
        for (auto b : order){
            if (v >> b & 1){
                if (gauss[b]){
                    v ^= gauss[b];
                } else {
                    gauss[b] = v;
                    break;
                }
            }
        }
    }

    int64 y = 0;

    for (auto b : order) {
        if (y >> b & 1)
            continue;

        if (gauss[b])
            y ^= gauss[b];
    }

    cout << (y + (y ^ x)) << endl;

    return 0;
}