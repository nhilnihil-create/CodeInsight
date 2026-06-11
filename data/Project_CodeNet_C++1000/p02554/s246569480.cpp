#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

const int mod = 1000000007;

long long int powmod(int x, int n){
    long long int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = (ans * x) % mod;
    }

    return ans;
}

int main(){
    int n;
    std::cin >> n;

    long long int ans = powmod(10, n) - powmod(9, n) - powmod(9, n) + powmod(8, n);
    ans %= mod;
    ans = (ans + mod) % mod;

    std::cout << ans << std::endl;

    return 0;
}