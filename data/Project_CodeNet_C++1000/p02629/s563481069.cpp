#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll N;
    cin >> N;
    string res = "";

    while (N) {
        --N;
        res += (char)('a' + (N % 26));
        N = N/26;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}