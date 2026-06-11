#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

typedef long long ll;

ll count(ll T1, ll T2, ll A1, ll A2, ll B1, ll B2) {
    if ((A1 - B1)*T1 < (B2 - A2)*T2) {
        return count(T1, T2, B1, B2, A1, A2);
    }

    if (A1*T1 > B1*T1) return 0;
    if (A1*T1 == B1*T1) return 1;
    ll d1 = (B1 - A1)*T1;
    ll d = (A1 - B1)*T1 + (A2 - B2)*T2;
    

    if (d1 % d == 0) {
        ll x = d1 / d;
        return 2*x;
    } else {
        ll x = (d1 / d) + 1;
        return 2*x - 1;
    }
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    ll T1, T2, A1, A2, B1, B2;
    std::cin >> T1 >> T2;
    std::cin >> A1 >> A2;
    std::cin >> B1 >> B2;

    if ((A1 - B1)*T1 == (B2 - A2)*T2) {
        std::cout << "infinity" << std::endl;
        return 0;
    }

    std::cout << count(T1, T2, A1, A2, B1, B2) << std::endl;
    return 0;
}
