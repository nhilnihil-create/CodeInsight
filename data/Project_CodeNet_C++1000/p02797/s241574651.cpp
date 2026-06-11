//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define chmin(x,y) x = min(x, y)
#define chmax(x,y) x = max(x, y)
#define V vector
vector<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};
vector<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};

int main () {
    int n, k, s; cin >> n >> k >> s;
    rep(i, k) printf("%d ", s);
    rep(i, n-k) {
        if (s == 1e9) printf("1 ");
        else printf("1000000000 ");
    }
    cout << endl;

    return 0;
}