//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


inline void print() {
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest) {
    cout << first << ' ';
    print(rest...);
}


void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    vector<int> plus, minus;

    minus.push_back(A[0]);
    plus.push_back(A[N-1]);
    for (int i = 1; i < N-1; i++) {
        if (A[i] < 0) minus.push_back(A[i]);
        else plus.push_back(A[i]);
    }

    int sum = accumulate(plus.begin(), plus.end(), 0) - accumulate(minus.begin(), minus.end(), 0);

    cout << sum << endl;

    int x = minus[0];
    for (int i = 1; i < plus.size(); i++) {
        print(x, plus[i]);
        x = x - plus[i];
    }
    print(plus[0], x);
    x = plus[0] - x;
    for (int i = 1; i < minus.size(); i++) {
        print(x, minus[i]);
        x = x - minus[i];
    }
}


int main() {
    solve();
    return 0;
}