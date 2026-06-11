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
    int N, K;
    cin >> N >> K;

    int path = ((N - 1) * (N - 2)) / 2;

    if (K > path) {
        cout << -1 << endl;
        return 0;
    }
    
    int M = N - 1 + (path - K);
    cout << M << endl;

    rep(i, N - 1) {
        cout << 1 << " " << (i + 2) << endl;
    }

    int diff = path - K;
    repd(i, 2, N + 1) {
        repd(j, i + 1, N + 1) {
            if (diff <= 0) break;
            diff--;
            cout << i << " " << j << endl;
        }
        if (diff <= 0) break;
    }
    return 0;
}