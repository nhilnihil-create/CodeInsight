#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    long N;
    cin >> N;
    if (N == 1) cout << 0 << endl;
    else {
        long num = N;
        int res = 0;
        for (long i = 2; i * i <= N; i++) {
            int cnt = 0;
            while (num % i == 0) {
                num /= i;
                ++cnt;
            }
            int j = 1;
            while (cnt - j >= 0) {
                cnt -= j;
                ++res;
                ++j;
            }
        }
        if (num != 1) ++res;
        cout << res << endl;
    }
}

