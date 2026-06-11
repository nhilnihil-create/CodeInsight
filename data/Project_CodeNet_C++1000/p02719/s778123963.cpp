#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;

    ll a = N / K;
    cout << min(N - K*a, abs(N - K*(a + 1))) << endl;

    return 0;
}