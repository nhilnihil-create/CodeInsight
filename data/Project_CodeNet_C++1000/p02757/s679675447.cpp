#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    int P;
    cin >> N >> P;
    string s; cin >> s;
    vector<long long> x(P, 0);
    long long d = 1;
    long long k = 0;
    x[k]++;
    long long ans = 0;
    if(P == 2 || P == 5) {
        for (int i = 0; i < N; i++)
        {
            if((s[N-1-i] - '0') % P == 0) ans += N-i;
        }
        cout << ans << endl;
    }
    else {
        for (int i = 0; i < N; i++) {
            k = (k + (s[N-1-i] - '0') * d) % P;
            d = (d * 10) % P;
            x[k]++;
        }
        for (int i = 0; i < P; i++)
        {
            ans += x[i] * (x[i]-1) / 2;
        }
        cout << ans << endl;
    }
}