#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

ll X;

int main() {
    cin >> X;
    int step = 0;
    ll cur = 100;
    while(cur < X) {
        cur += cur/100;
        step++;
    }
    cout << step << endl;
}
