#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> c;
const int p = 3;

void dfs(string s) {
    if (s.size() == p) {
        c.push_back(s);
        return;
    }
    else {
        for (int i = 0; i < 10; i++) {
            s += to_string(i);
            dfs(s);
            s.pop_back();
        }
    }
}


int main() {

    int N; cin >> N;
    string s; cin >> s;
    string t;
    dfs(t);
    ll ans = 0;    
    for (int i = 0; i < c.size(); i++) {
        string tmp = c[i];
        int index = 0;
        bool ok = false;
        for (int j = 0; j < s.size(); j++) {
            if (tmp[index] == s[j]) {
                index++;
            }
        }
        if (index == 3) ok = true;
        if (ok) {
            ans++;
        }
    }
	cout << ans << endl;
    return 0;
}