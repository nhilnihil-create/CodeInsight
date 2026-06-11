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
    vector<long long> A(N+1), B(N);
    for (int i = 0; i < N+1; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    long long ans = 0;
    long long help = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > help + B[i]) {
            ans += help + B[i];
            help = 0;
        }
        else{
            ans += A[i];
            if (A[i] <= help) help = B[i];
            else help = help + B[i] - A[i];
        }
    }
    ans += min(help, A[N]);

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}