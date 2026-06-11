#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
ll n, k, c, repeat_time, pre_repeat_time;
int main() {
    bool repeat_exist = false;
    std::cin >> n >> k;
    std::vector<ll> vec(n+1, 0);
    std::vector<long long int> b(n+1, -1);
    for (ll i = 1; i <= n; i++) {
        cin >> vec[i];
    }
    ll j = 1;
    c = 1;
    while (c <= k) {
        if (b[j] != -1) {
            repeat_time = c - b[j];
            pre_repeat_time = b[j] - 1;
            repeat_exist = true;
            break;
        }
        b[j] = c;
        j = vec[j];
        c++;
    }
    if (repeat_exist) {
        ll x = (k - pre_repeat_time) % repeat_time;
        for (ll p = 0; p < x; p++) {
            j = vec[j];
        }
        std::cout << j << std::endl;
    }
    else {
        std::cout << j << std::endl;
    }

}