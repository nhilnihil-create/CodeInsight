#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
#define rep(i, n) for (int i=0; i<int(n); i++)

int main() {
    int n; cin >> n;
    string s,t; cin >> s >> t;
    rep(i,n) {
        cout << s[i] << t[i];
    }
    cout << endl;
}