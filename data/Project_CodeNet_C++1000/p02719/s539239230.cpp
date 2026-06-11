#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    ll N, K;
    cin >> N >> K;
    ll min_value = N;
    if(N >= K) {
        N = N % K;
        min_value = min(min_value, N);
    }
    if (N <= K ) {
        N = K - N;
        min_value = min(min_value, N);
    }
    cout << min_value << endl;
}