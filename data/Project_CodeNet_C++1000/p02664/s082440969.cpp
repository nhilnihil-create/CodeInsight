#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }

const int maxn = 1e6 + 11;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string s; cin >> s;
    int n = (int)s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') s[i] = 'D';
    }

    out(s);
    
    
    return 0;
}
