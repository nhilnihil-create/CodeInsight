#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int A, B, C, K;

int main() {
    cin >> A >> B >> C >> K;
    if (K <= A) {
        cout << K << endl;
        return 0;
    }
    if ( K <= A + B) {
        cout << A << endl;
        return 0;
    }
    if (K <= A + B + C) {
        cout << A - (K - A - B) << endl;
        return 0;
    }
    cout << A - C << endl;
}
