#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<int> ps;
vector<int> qs;
vector<int> rs;

vector<int> cands;

int main(void) {
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    ps.resize(A);
    for (int i = 0; i < A; i++) {
        cin >> ps[i];
    }
    sort(ps.begin(), ps.end());
    reverse(ps.begin(), ps.end());

    qs.resize(B);
    for (int i = 0; i < B; i++) {
        cin >> qs[i];
    }
    sort(qs.begin(), qs.end());
    reverse(qs.begin(), qs.end());

    rs.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> rs[i];
    }
    // don't have to sort rs here

    for (int i = 0; i < X; i++) {
        cands.push_back(ps[i]);
    }
    for (int i = 0; i < Y; i++) {
        cands.push_back(qs[i]);
    }
    for (int i = 0; i < C; i++) {
        cands.push_back(rs[i]);
    }
    sort(cands.begin(), cands.end());
    reverse(cands.begin(), cands.end());

    ll ans = 0;
    for (int i = 0; i < X + Y; i++) {
        ans += cands[i];
    }

    cout << ans << endl;

    return 0;
}
