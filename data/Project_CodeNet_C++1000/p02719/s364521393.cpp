#include <bits/stdc++.h>
using namespace std;

int main (){
    long long N, K;
    cin >> N >> K;
    long long ans = N;
    if(N > K) {
        ans = min(N%K,K - N%K);
    } else if(N == K) {
        ans = 0;
    } else {
        ans = min(N, K - N);
    }
    cout << ans << endl;
}