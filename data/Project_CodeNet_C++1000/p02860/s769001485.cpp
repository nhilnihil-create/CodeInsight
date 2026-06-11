#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/dsu>
//using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001000;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    if (n%2) {
        printf("No\n");
        return 0;
    } else {
        rep(i,n/2) {
            if (s[i] != s[i+n/2]) {
                printf("No\n");
                return 0;
            }
        }
        printf("Yes\n");
    }
    return 0;
}
