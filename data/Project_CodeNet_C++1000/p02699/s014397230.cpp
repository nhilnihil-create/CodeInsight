#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
#define COUT(x) cout << (x) << endl
#define ENDL cout << endl
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1000000000;

int main() {
    int S, W;
    cin >> S >> W;
    if (S <= W) {
        COUT("unsafe");
    } else {
        COUT("safe");
    }
    return 0;
}