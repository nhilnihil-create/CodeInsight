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
    int N, M;
    cin >> N >> M;
    vector<int> num(N, 1);
    vector<bool> check(N, false);
    if (N == 1 && M == 0) {
        cout << 0 << endl;
        return 0;
    }
    rep(i, M) {
        int s, c;
        cin >> s >> c;
        s--;
        if (check[s] && num[s] != c) {
            cout << -1 << endl;
            return 0;
        } else {
            num[s] = c;
        }
        check[s] = true;
    }

    if (N >= 2 && num[0] == 0) {
        cout << -1 << endl;
    } else {
        rep(i, N) {
            if (!check[i] && i != 0) cout << 0;
            else cout << num[i];
        }
        cout << endl;
    }
    return 0;
}