#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int N;
ll res = 0;

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        if (i%3!=0 && i%5!=0) res += i;
    }
    cout << res << endl;
}
