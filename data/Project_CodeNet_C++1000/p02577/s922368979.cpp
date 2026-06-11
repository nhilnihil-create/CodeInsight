#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)//rep(i,回数){処理}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    ll ans;
    cin >> s;
    
    rep(i,s.length()) {
        ans += int(s[i] - '0');
    }
   
    if (ans%9 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}