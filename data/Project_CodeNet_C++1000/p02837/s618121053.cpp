#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int N;
    cin >> N;
    
    vector<vector<int>> X(N), Y(N);

    rep(i, N) {
        int A;
        cin >> A;
        rep(j, A) {
            int x, y;
            cin >> x >> y;
            X[i].push_back(x);
            Y[i].push_back(y);
        }
    }

    int ans = 0;
    rep(bit, 1 << N) {
        int cnt = 0;
        vector<bool> liar(N, false);
        rep(i, N) {
            if ((bit >> i) & 1) {
                cnt++;
                liar[i] = true;
            }
        }

        bool flag = true;
        rep(i, N) {
            if (!liar[i]) continue;
            rep(j, X[i].size()) {
                if (liar[X[i][j] - 1] != Y[i][j]) flag = false;
            }
        }

        if (flag) chmax(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}