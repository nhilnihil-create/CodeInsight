/*

(x + y)%2019 = 0

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 2019

const int ma = 6;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    ll num = 0;
    ll pot = 1;
    ll cnt = 0;
    vector<int> u(mod);
    u[num]++;

    for (int i=n-1;i>=0;i--) {
        num = (num + (((int)(s[i] - '0')) * pot))%mod;
        cnt += u[num];
        u[num]++;
        pot  = (pot*10)%mod;
    }

    cout << cnt << "\n";
}
