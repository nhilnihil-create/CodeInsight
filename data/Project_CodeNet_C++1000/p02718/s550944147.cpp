#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int N, M;

int main() {
    cin >> N >> M;
    vector<int> a(N);
    int tot = 0;
    rep(i,N) cin >> a[i], tot += a[i];
    sort(RALL(a));
    int th = (tot - 1 + 4*M)/4/M;
    rep(i,M) {
        if (a[i] < th) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
