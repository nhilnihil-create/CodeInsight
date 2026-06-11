#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii; 
const int N = 2e5+10, mod = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    for (int i = 0; i < s.size(); ++i) {
        s[i] = ((s[i] - 'A' + n) % 26) + 'A';
        
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    return 0;
}