#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, k;   cin >> n >> k;
    
    long long ans = 0, i, mod = 1e9+7;
    for (i = 0; i <= n - k + 1; i++) {
        ans += (k+i)*(2*n+1-(k+i))/2%mod - (k+i-1)*(k+i)/2%mod + 1;
        ans %= mod;
    }

    cout << (ans+mod)%mod << endl;

    return 0;
}