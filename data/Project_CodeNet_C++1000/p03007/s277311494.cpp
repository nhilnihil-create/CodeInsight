#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
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

vector<int> A;

int solve(const int N, vector<string> &output) {
    int max_val = A[0];
    int min_val = A[N - 1];

    int acc = min_val;
    int idx = 1;
    for (; idx < N - 1; idx++) {
        if (A[idx] < 0) break;
        output.push_back(to_string(acc) + " " + to_string(A[idx]));
        acc = acc - A[idx];
    }

    int ans = A[0];
    for (; idx < N - 1; idx++) {
        output.push_back(to_string(ans) + " " + to_string(A[idx]));
        ans = ans - A[idx];
    }

    output.push_back(to_string(ans) + " " + to_string(acc));
    return ans - acc;
}

int main(void) {
    int N;
    cin >> N;

    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    vector<string> output;
    int ans = solve(N, output);
    cout << ans << endl;
    for (auto &str : output) {
        cout << str << endl;
    }

    return 0;
}
