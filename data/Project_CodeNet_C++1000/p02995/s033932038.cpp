#include<iostream>
#include<vector>
#include<string>

using ll = long long;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

// おまけ
long long lcm(long long a, long long b){
    return a * (b / gcd(a, b));
}

int main(){
    ll a, b, c, d;
    std::cin >> a >> b >> c >> d;
    // c, dで割り切れるもの
    ll canC = b / c - (a + c - 1) / c + 1;
    ll canD = b / d - (a + d - 1) / d + 1;
    // cとdで割り切れるもの
    ll LCM = lcm(c, d);
    ll canCD = b / LCM - (a + LCM - 1) / LCM + 1;
    std::cout << (b - a + 1) - (canC + canD - canCD) << std::endl;
    return 0;
}
