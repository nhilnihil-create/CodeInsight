#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

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

vector<ll> A;
vector<ll> S;

map<ll, ll> counter;

int main(void) {
    ll N, K;
    cin >> N >> K;

    A.resize(N + 1, 0);
    S.resize(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i + 1];
        S[i + 1] = S[i] + A[i + 1];
    }

    ll acc = 0;
    for (int i = 0; i <= N; i++) {
        ll x = (S[i] - i) % K;
        // printf("i: %d, S[i]: %lld, x: %lld\n", i, S[i], x);
        if (i - K >= 0) {
            ll y = (S[i - K] - (i - K)) % K;
            counter[y]--;
        }
        acc += counter[x];
        counter[x]++;
    }

    cout << acc << endl;

    return 0;
}
