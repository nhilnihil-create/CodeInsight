#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>
#include <bitset>
#include <sstream>
#include <cassert>
#include <time.h>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}
void printvec (vec &v) {
    Rep (i, (ll)v.size()) {
        cout << v[i] << " \n"[i+1 == (ll)v.size()];
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    vec P(N), C(N);
    Rep (i, N) {
        cin >> P[i];
        P[i]--;
    }
    Rep (i, N) {
        cin >> C[i];
    }

    ll ans = -inf;

    Rep (i, N) {
        ll now = i;
        vector<bool> visited(N, false);
        ll scorePerLoop = 0;
        ll cnt = 0;
        while (!visited[now]) {
            visited[now] = true;
            now = P[now];
            scorePerLoop += C[now];
            cnt++;
        }

        ll loops = K / cnt, rem = K % cnt;

        if (loops) {
            loops--;
            rem += cnt;
        }
        ll tmp = max<ll>(scorePerLoop, 0) * loops;
        ll highest = -inf;
        while (rem--) {
            now = P[now];
            tmp += C[now];
            chmax(highest, tmp);
        }
        chmax(ans, highest);
    }

    cout << ans << endl;
}