#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N; cin >> N;
    vector<long long>A(N);
    for (long long i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<long long>B = A;
    for (long long i = 1; i < N; i++) {
        B.at(i) = B.at(i - 1) ^ B.at(i);
    }
    long long num = B.at(N - 1);
    for (long long i = 0; i < N; i++) {
        long long ans = A.at(i);
        cout << (num ^ ans);
        if (i != N - 1) cout << ' ';
    }
}