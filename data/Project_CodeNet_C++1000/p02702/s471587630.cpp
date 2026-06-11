#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    string s;
    cin >> s;

    const uint64_t MOD = 2019;
    uint64_t answ = 0;
    uint64_t pow = 1;
    uint64_t num = 0;
    uint64_t d[2020];
    fill(d, d + 2020, 0);
    reverse(s.begin(), s.end());
    d[0] = 1;
    for(const auto& c: s) {
        num = (num + (c - '0') * pow) % MOD;
        answ += d[num]++;
        pow = (pow * 10) % MOD;
    }
    cout << answ;
    return 0;
}