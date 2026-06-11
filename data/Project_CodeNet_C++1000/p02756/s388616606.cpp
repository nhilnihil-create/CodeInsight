#include <bits/stdc++.h>
using namespace std;
int main() {
    int q;
    string s, pre, post;
    long long ans;
    bool r = 0;
    cin >> s >> q;
    for (int i = 0; i < q; i++) {
        int t,f;
        string c;
        cin >> t;
        if (t == 2) {
            cin >> f >> c;
            if ((f*2 - 3)*(r*2 - 1) == 1) {
                pre += c;
            }else{
                post += c;
            }
        }else r = !r;
    }
    reverse(pre.begin(), pre.end());
    s = pre + s + post;
    if (r) {
        reverse(s.begin(), s.end());
    }

    cout << s << endl;

}

