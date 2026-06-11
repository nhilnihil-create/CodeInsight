#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

#define ll long long

int main()
{
    ll k, n;
    std::cin >> k >> n;

    std::vector<ll> A(n);
    ll diff = 0;

    for(ll i=0; i < n; i++) {
        std::cin >> A[i];
        if(i > 0) {
            if((A[i]-A[i-1]) > diff) {
                diff = A[i]-A[i-1];
            }
        }
    }

    ll x = k + A[0] - A[n-1];
    if(x > diff) {
        diff = x;
    }
    
    std::cout << k-diff << std::endl;
}