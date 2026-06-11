#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

bool is_valid_parenthese(string s) {
    int cnt = 0;
    for(char c: s) {
        if (c == '(') cnt += 1;
        else cnt -= 1;
        if (cnt < 0) return false;
    }
    return cnt == 0;
}

int main() {
    //   BWBBWWWB
    //=> ((())())
    //=> 2*3*2*1 rev, x 4!
    int n;
    ll mod = 1e9 + 7;
    string s;
    cin >> n >> s;
    if (s[0] == 'W') {
        cout << "0" << endl;
        return 0;
    }
    string paren = "(";
    int cnt = 1;
    for(int i = 1; i < n*2; i++) {
        if (s[i] == 'W') {
            if (cnt % 2 == 1) {
                paren += '(';
                cnt += 1;
            } else {
                paren += ')';
                cnt -= 1;
            }
        } else {// s[i] == 'B';
            if (cnt % 2 == 1) {
                paren += ')';
                cnt -= 1;
            } else {
                paren += '(';
                cnt += 1;
            }
        }
    }
    // cout << ans << endl;
    if (!is_valid_parenthese(paren)) {
        cout << 0 << endl;
        return 0;
    } else {
        ll mul = 0;
        ll ans = 1;
        for(int i = n*2-1; i >= 0; i--) {
            if (paren[i] == ')') {
                mul += 1;
            } else {
                ans *= mul;
                ans %= mod;
                mul -= 1;
            }
        }
        for(int i = 1; i <= n; i++) {
            ans *= i;
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}


