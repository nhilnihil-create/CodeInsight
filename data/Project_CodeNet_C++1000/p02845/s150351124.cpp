#include <algorithm>
#include <iostream>
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

const ll MOD = ll(1e9 + 7);

vector<int> A;

ll solve(const int N) {
    int counter_r = 0;
    int counter_g = 0;
    int counter_b = 0;
    ll acc = 1;

    for (const auto &a : A) {
        int num = 0;
        if (counter_r == a) num++;
        if (counter_b == a) num++;
        if (counter_g == a) num++;

        acc = (acc * num) % MOD;

        if (counter_r == a) {
            counter_r++;
        } else if (counter_b == a) {
            counter_b++;
        } else if (counter_g == a) {
            counter_g++;
        }
    }

    return acc;
}

int main(void) {
    int N;
    cin >> N;

    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve(N) << endl;

    return 0;
}
