#include <bits/stdc++.h>
using namespace std;

int ans(long long N, long long K){
    if (N<K) return 1;
    return ans(N/K, K)+1;
}

int main() {
    long long N, K;
    cin >> N >> K;
    cout << ans(N, K) << endl;
}