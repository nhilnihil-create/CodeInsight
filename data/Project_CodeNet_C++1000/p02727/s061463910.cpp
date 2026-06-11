#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<ll, int> P;
int main()
{
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    priority_queue<P> que;
    rep(i, A) {
        ll q;
        cin >> q;
        que.push({q, 1});
    }
    rep(i, B) {
        ll q;
        cin >> q;
        que.push({q, 2});
    }
    rep(i, C) {
        ll q;
        cin >> q;
        que.push({q, 0});
    }

    int sum = 0;
    ll ans = 0;
    int a = 0, b = 0, c = 0;
    while (sum < X + Y) {
        ll d = que.top().first;
        int k = que.top().second;
        que.pop();
        if (k == 1) {
            if (a < X) {
                ans += d;
                sum++;
                a++;
            }
        }
        else if (k == 2) {
            if (b < Y) {
                ans += d;
                sum++;
                b++;
            }
        }
        else {
            sum++;
            ans += d;
        }
    }

    cout << ans << endl;
    return 0;
}