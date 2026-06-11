#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using ull = unsigned long long;
using ll = long long;
using namespace std;

int main(void) {
    ll N, K;
    cin >> N >> K;

    ll ans = N;
    if (N <= K) {
        ans = min(ans, abs(N-K));
        cout << ans << endl;
        return 0;
    } else {
        
        ans = N % K;
        ans = min(ans, abs(ans-K));
        cout << ans << endl;
        return 0;
    }

    return 0;
}