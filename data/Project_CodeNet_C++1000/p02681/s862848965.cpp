#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string S;
    cin >> S;
    string T;
    cin >> T;
    T = T.substr(0, sz(T) - 1);
    bool bl = S == T;
    puts(bl ? "Yes" : "No");
    return 0;
}