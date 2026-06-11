#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    long long N, K;
    cin >> N >> K;

    long long r_p = N % K;
    long long r_m = K - r_p;
    long long ans = min({r_p, r_m});

    cout << ans << endl;
    return 0;
}