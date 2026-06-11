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

vector<int> smalls;
vector<int> bigs;

int main(void) {
    int N;
    cin >> N;

    smalls.resize(N);
    bigs.resize(N);
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        smalls[i] = A;
        bigs[i] = B;
    }
    sort(smalls.begin(), smalls.end());
    sort(bigs.begin(), bigs.end());

    if (N % 2 == 0) {
        int l = smalls[N / 2 - 1] + smalls[N / 2];
        int r = bigs[N / 2 - 1] + bigs[N / 2];
        cout << r - l + 1 << endl;
    } else {
        int l = smalls[N / 2];
        int r = bigs[N / 2];
        cout << r - l + 1 << endl;
    }

    return 0;
}
