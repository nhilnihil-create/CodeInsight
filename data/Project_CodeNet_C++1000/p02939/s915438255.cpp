#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    string s;
    cin >> s;
    int ans = 0;
    string t, p = "";
    rep(i, s.size()) {
        t += s[i];
        if (t == p) continue;
        p = t;
        t = "";
        ans++;
    }
    cout << ans << endl;

    return 0;
}