#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;

long long power(long long a, long long p) {
    long long res = 1;
    while (p) {
        if (p & 1) res = (res * a) % mod;
        p >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> n;
    long long ans = power(10, n) - 2 * power(9, n) + power(8, n);
    cout << (ans % mod + mod) % mod << '\n';

    return 0;
}
