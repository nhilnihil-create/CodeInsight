#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    ans = min(N%K, abs(K-N%K));
    cout << ans << endl;
}