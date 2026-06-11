#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

const ll MAX = 110000;
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int main() {
    int N; cin >> N;
    vector<int> a(N), b(N);

    vector<ll> vec(110000);

    for (int i = 1; i <= N; ++i) {
        vec[i - 1] = i;
    }
    
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    }

    //aを昇順に
    if (a > b) swap(a, b);

    //順列生成、カウント
    int ans = 0;
    do {
        if(a == b) break;
        ++ans;
    } while (next_permutation(a.begin(), a.end()));

    cout << ans << '\n';

    return 0;
}