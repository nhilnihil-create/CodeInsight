#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < N; i++)
#define INF (INT64_MAX /2)


























int main() {
    long long N;
    cin >> N;
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += N / i;
        if (N %i == 0) ans--;
    }   
    cout << ans << endl;
}