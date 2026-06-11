#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, K;
    long long ans = 0;
    cin >> N >> K;
    for (long long i = K; i <= N+1; i++){
        //cout <<(N - i + 1)*i << endl;
        ans += (N - i + 1)*i + 1;
        ans = ans % ((long long) 1e9 + 7);
    }
    cout << ans << endl;

}
