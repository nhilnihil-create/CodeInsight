#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int N, K;
vector<double> A(0);

int lower_bound_func(int left, int right, bool (*func)(int)) {
    // func returns true when the statement is satisfied
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (func(mid))
            right = mid;
        else
            left = mid;
    }
    return right;  // left for upper_bound
}

bool check(int output) {
    ll tmp = 0;
    for (int i = 0; i < N; i++) {
        tmp += ceil(A[i] / (double)output);
    }
    return tmp - N <= K;
}

int main() {
    cin >> N >> K;

    A.resize(N);
    int m = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        m = max(m, (int)A[i]);
    }
    if (K == 0) {
        cout << m << endl;
        return 0;
    }

    int output = lower_bound_func(0, m, check);

    cout << output << endl;

    return 0;
}
