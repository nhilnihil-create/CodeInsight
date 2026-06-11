#include <bits/stdc++.h>

using namespace std;

int add (int a , int b , int mod) {
    a += b;
    while (a >= mod) a -= mod;
    while (a < 0) a += mod;
    return a;
}

int mul (int a , int b , int mod) {
    return a * 1ll * b % mod;
}

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#ifdef LOCAL
    freopen("input.in" , "r" , stdin);
#endif
    int n , p;
    string s;
    cin >> n >> p >> s;

    long long ans = 0;
    if (p == 2) {
        for (int i = 0 ; i < n ;i++) {
            int d = s[i] - '0';
            if (d % 2 == 0)
                ans += i + 1;
        }
    } else if (p == 5) {
        for (int i = 0 ; i < n ;i++) {
            int d = s[i] - '0';
            if (d == 5 || d == 0)
                ans += i + 1;
        }
    } else {
        reverse(s.begin() , s.end());

        vector<int> f(p);
        f[0]++;

        int power = 1 , h = 0;
        for (int i = 0 ;i < n ;i++) {
            int d = s[i] - '0';
            h = add(h , mul(power , d , p) , p);
            ans += f[h];
            f[h]++;
            power = mul(power , 10 , p);
        }
    }

    cout << ans;
}