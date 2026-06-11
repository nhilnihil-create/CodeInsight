#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    string ns;
    rep(i, n) {
        ns.push_back(s[i]);
        if(s[i] == s[i+1]) ns.pop_back();
    }
    cout << ns.size() << endl;
    return 0;
}