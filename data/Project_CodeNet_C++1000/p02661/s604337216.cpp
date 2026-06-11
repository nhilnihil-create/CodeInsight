#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <bitset>

#define ll long long

int main()
{
    ll N;
    std::cin >> N;

    std::vector<ll> A(N), B(N);
    for(ll i=0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    if(N%2==1) {
        // 奇数の時
        ll ans = B[N/2] - A[N/2]+1;
        std::cout << ans << std::endl;
    }
    else {
        // 偶数の時
        ll now1 = B[N/2] + B[N/2-1];
        ll now2 = A[N/2] + A[N/2-1];
        ll ans = now1-now2+1;
        std::cout << ans << std::endl;
    }
}