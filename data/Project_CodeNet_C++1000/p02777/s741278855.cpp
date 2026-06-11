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
    string S, T, U;
    int A, B;
    cin >> S >> T >> A >> B >> U;

    if (U == S) A--;
    if (U == T) B--;

    print(A, B);
}


int main() {
    solve();
    return 0;
}