#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    int N, M;
    cin >> N >> M;
    multiset<long long> A;
    for(size_t i = 0; i < N; i++) {
        long long a;
        cin >> a;
        A.insert(a);
    }
    for(int i = 0; i < M; i++) {
        auto itr = A.end();
        itr--;
        long long a = *itr;
        A.erase(itr);
        A.insert(a / 2);
    }
    // ans = accumulate(A.begin(), A.end(), 0);
    for(long long a : A) {
        // cout << a << " ";
        ans += a;
    }
    // cout << endl;
    cout << ans << endl;
}