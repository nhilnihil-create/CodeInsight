#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t S;
    cin >> S;
    const constexpr int64_t d = 1e9;
    printf("%ld %ld %ld %ld %ld %ld\n", 0, 0, d, 1, (d - S % d) % d, S / d + (S % d == 0 ? 0 : 1));
}