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

    vector<vector<int>> AB(1e5 + 1);

    rep(i, N) {
        int A, B;
        cin >> A >> B;
        AB[A].push_back(B);
    }

    priority_queue<int> pque;

    int ans = 0;
    repd(i, 1, M + 1) {
        rep(j, AB[i].size()) {
            pque.push(AB[i][j]);
        }
        if (!pque.empty()) {
            int p = pque.top();
            pque.pop();
            ans += p;
        }
    }

    cout << ans << endl;
    return 0;
}