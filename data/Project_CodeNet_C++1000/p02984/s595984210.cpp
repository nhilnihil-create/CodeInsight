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

int N;
vector<int> A(0);

int lower_bound_func(int left, int right, bool (*func)(int)) {
    // func returns true when the statement is satisfied
    // watch out for initialization of left
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (func(mid))
            right = mid;
        else
            left = mid;
    }
    return right;  // left for upper_bound
}

bool calc(int l) {
    int tmp = l;
    for (int i = 0; i < N - 1; i++) {
        tmp = A[i] - tmp;
    }
    return (l + tmp) >= A[N - 1];
}

int main() {
    cin >> N;

    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int result = lower_bound_func(-1, A[0], calc);
    // for (int i = 0; i <= A[0]; i++) {
    // if (calc(i)) {
    // cout << "true" << endl;
    // } else {
    // cout << "false" << endl;
    // }
    // }

    int tmp = result;
    for (int i = 0; i < N; i++) {
        cout << tmp * 2 << " ";
        tmp = A[i] - tmp;
    }
    cout << endl;

    return 0;
}
