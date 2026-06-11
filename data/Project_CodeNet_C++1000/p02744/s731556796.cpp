#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
const int INF = 1e18, MOD = 998244353;
int n;
void search(string s, char c) {
    if (s.size() == n) {
        cout<<s<<endl;
    } else {
        for (char i = 'a'; i <= c; i++) {
            if (i == c) search(s + i, c + 1);
            else search(s + i, c);
        }
    }
}
signed main() {
    cin>>n;
    search("", 'a');
}