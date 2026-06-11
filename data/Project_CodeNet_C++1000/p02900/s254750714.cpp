#include <bits/stdc++.h>

using namespace std;

set<long long> pf(long long n) {
    set<long long> pf = {1};
    for (int i = 2 ;i * 1ll * i <= n ;i++) {
        while (n % i == 0) {
            pf.insert(i);
            n /= i;
        }
    }
    pf.insert(n);
    return pf;
}

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    long long a , b;
    cin >> a >> b;

    set<long long> aa = pf(a) ;
    set<long long> bb = pf(b);

    int res = 0;
    for (long long f : aa)
        if (bb.count(f))
            res++;

    cout << res;
}
