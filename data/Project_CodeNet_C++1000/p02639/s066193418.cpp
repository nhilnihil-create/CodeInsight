#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int x[5];

int main() {
    rep(i,5) {
        cin >> x[i];
        if (x[i] == 0) {
            cout << i+1 << endl;
            return 0;
        }
    }
}
