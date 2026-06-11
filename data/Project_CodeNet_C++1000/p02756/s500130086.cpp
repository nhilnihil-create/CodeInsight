#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, n) for(i = 0; i < n; i++)

int main(){
    string s, front, end;
    int i;
    int Q, q, f;
    bool reversed = false;
    char c;

    cin >> s;
    cin >> Q;
    rep (i, Q) {
        cin >> q;
        if (q == 1) {
            reversed ^= 1;
        } else {
            cin >> f;
            f = (f + reversed - 1) % 2 + 1;
            if (f == 1) {
                cin >> c;
                front += c;
            } else {
                cin >> c;
                end += c;
            }
        }
    }
    
    reverse(front.begin(), front.end());
    string ans = front + s + end;
    if (reversed) {
        reverse(ans.begin(), ans.end());
    }
    cout << ans;

    return 0;
}