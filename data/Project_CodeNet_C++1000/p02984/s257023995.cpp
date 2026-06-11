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

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    int64_t sum = 0;
    int64_t evensum = 0;
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
        if(i%2 == 1) {
            evensum += A[i];
        }
    }

    vector<int64_t> X(N+1);
    X[0] = sum - (evensum*2);

    rep(i, N) {
        X[i+1] = A[i] * 2 - X[i];
    }

    rep(i, N) {
        cout << X[i] << " ";
    }
    cout << endl;

    return 0;
}

