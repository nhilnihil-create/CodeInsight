#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int main() {
    st num;
    cin >> num;
    ll sum = 0;
    rep(i, num.size()){
        int dig = num.at(i) - '0';
        sum += dig;
    }
    if(sum % 9 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}