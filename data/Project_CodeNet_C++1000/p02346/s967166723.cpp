#include <iostream>
#include <algorithm>
using namespace std;

template<typename T, int MAX_N>
struct BIT {
    int N;
    T arr[MAX_N];

    BIT (int n) : N(n) {
        for (int i = 0; i <= N; ++i) {
            arr[i] = (T)0;
        }
    }

    void add (int i, T a) {
        for (int x = i; x <= N; x += x & -x) {
            arr[x] += a;
        }
    }

    T query(int i) {
        T val = 0;
        for (int x = i; x > 0; x -= x & -x) {
            val += arr[x];
        }
        return val;
    }
};

int N, Q;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> Q;
    BIT<int, 101010> bit(N);
    for (int j = 0; j < Q; ++j) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            bit.add(x, y);
        } else {
            cout << (bit.query(y) - bit.query(x-1)) << endl;
        }
    }
    return 0;
}