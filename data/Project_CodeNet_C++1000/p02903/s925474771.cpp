#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;

int main() {
    ll H, W, A, B;
    cin >> H >> W >> A >> B;

    rep(i, H) {
        if (i < B) {
            rep(k, A) { cout << 0; }
            rep(k, W - A) { cout << 1; }
            cout << endl;
        } else {
            rep(k, A) { cout << 1; }
            rep(k, W - A) { cout << 0; }
            cout << endl;
        }
    }

    return 0;
}