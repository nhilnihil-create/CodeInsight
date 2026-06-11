#include <iostream>
#include <vector>

#define ll long long

int main() {
    ll N;
    ll sum = 0;

    std::cin >> N;
    std::vector<ll> data(N+1, 1);
    
    for(ll i=2; i <= N; i++) {
        for(ll j = i; j <= N; j += i) {
            data[j]++;
        }
    }

    for(ll i = 1; i <= N; i++) {
        sum += i * data[i];
    }
    std::cout << sum;
}