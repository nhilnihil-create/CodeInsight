#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

const int64_t kMOD = 1000000007;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }

    int64_t inner = 0;
    for(int i=0; i<N-1; ++i) {
        for(int j=i+1; j<N; ++j) {
            if(A[i] > A[j]) {
                inner++;
            }
        }
    }

    int64_t outer = 0;
    sort(A.rbegin(), A.rend());
    for(int i=0; i<N-1; ++i) {
        for(int j=i+1; j<N; ++j) {
            if(A[i] > A[j]) {
                outer++;
            }
        }
    }

    inner *= K;
    inner %= kMOD;


#if 1
    if(K % 2 == 0) {
        outer *= K / 2;
        outer %= kMOD;
        outer *= K - 1;
        outer %= kMOD;
    } else {
        outer *= (K-1) / 2;
        outer %= kMOD;
        outer *= K;
        outer %= kMOD;
    }
#else
    inner = inner * K;
    inner %= kMOD;

    outer *= K-1;
    outer %= kMOD;
    outer *= K;
    outer %= kMOD;
    outer /= 2;
#endif
//    cout << inner << " " << outer << endl;

    cout << (inner + outer) % kMOD << endl;

    return 0;
}

