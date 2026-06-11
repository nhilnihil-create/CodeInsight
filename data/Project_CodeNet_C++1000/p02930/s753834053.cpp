#include <bits/stdc++.h>

int main() {
    using namespace std;
    constexpr unsigned long MOD = 1000000007;
    unsigned long N;
    cin >> N;
    for(unsigned long i = 0; i < N; ++i){
        for(unsigned long j = i + 1; j < N; ++j)cout << __builtin_ffsl(i ^ j) << " ";
        cout << endl;
    }
    return 0;
}