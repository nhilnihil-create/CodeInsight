#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    if (a%b == 0) return b;
    else return gcd(b, a%b);
}

int main(int argc, char const *argv[]) {
    long long a, b;
    long long c, d;
    cin >> a >> b >> c >> d;

    long long ans = b - a + 1;
    long long num_c = b/c - (a-1)/c;
    long long num_d = b/d - (a-1)/d;
    long long num_cd = b/((c * d)/gcd(c, d)) - (a-1)/((c * d)/gcd(c, d));

    ans = ans - num_c - num_d + num_cd;
    cout << ans << endl;
    return 0;
}
