#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll N, K;
    cin >> N >> K;
    //cout << min(N % K, abs(N % K - K))<< "\n";
    ll t = N / K;
    cout << min(N - t * K, (t + 1) * K - N) << "\n";
    return 0;
}