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

    int A[10][10] = {};

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        string s = to_string(i);

        int head = s[0] - '0';
        int tail = s[s.size()-1] - '0';

        if (head == tail) ans++;

        ans += A[tail][head] * 2;

        A[head][tail]++;
    }

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}