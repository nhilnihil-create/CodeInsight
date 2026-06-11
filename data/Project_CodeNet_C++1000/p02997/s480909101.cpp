//
// Created by Hideaki Imamura on 2020-03-27.
//
# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

# define EPS (1e-7)
# define INF (1e9)
# define PI (acos(-1))
//const ll mod = 1000000007;

int N, K;

int main() {
    cin >> N >> K;
    if ((N - 1) * (N - 2) / 2 < K) cout << -1 << endl;
    else {
        cout << N - 1 + (N - 1) * (N - 2) / 2 - K << endl;
        for (int i = 2; i <= N; ++i) cout << 1 << " " << i << endl;
        int a = 2;
        int b = 3;
        for (int i = 0; i < (N - 1) * (N - 2) / 2 - K; ++i) {
            cout << a << " " << b << endl;
            b = (b + 1) % N;
            if (b == 1) {
                b = a + 2;
                a = a + 1;
            } else if (b == 0) b = N;
        }
    }
    return 0;
}