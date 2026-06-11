#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    string s, t;
    cin >> s >> t;
    bool flag = true;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != t[i]) flag = false;
    }
    if (s.length() + 1 != t.length()) flag = false;

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}