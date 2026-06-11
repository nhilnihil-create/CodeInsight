#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

ll N;

int main() {
    cin >> N;
    string res = "";
    while(N) {
        int z = N%26;
        if (z == 0) {
            res += (char)('z');
            --N;
        }
        else {
            res += (char)('a' + (z - 1));
        }
        N /= 26;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}