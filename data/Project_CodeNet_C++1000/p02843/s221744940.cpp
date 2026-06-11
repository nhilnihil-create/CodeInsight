#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;
// int64_t INF = 9223372036854775807;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t x;
    cin >> x;
    string res = "0";
    rep(i,1000){
        if(100*i<=x && x<=105*i){
            res = "1";
            break;
        }
    }
    cout << res << endl;
}