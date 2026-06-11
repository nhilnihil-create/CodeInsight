#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;



int main() {
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    a--, b--, c--, d--;
    bool ans = true;
    for(int i = a; i < c; ++i) if(s[i]=='#' && s[i+1]=='#') ans = false;
    for(int i = b; i < d; ++i) if(s[i]=='#' && s[i+1]=='#') ans = false;
    if(c < d) {
        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    if(c > d) {
        for(int i = b; i < min(n-1, d+1); ++i) {
            if(s[i-1]=='.' && s[i]=='.' && s[i+1]=='.') {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
    return 0;
}