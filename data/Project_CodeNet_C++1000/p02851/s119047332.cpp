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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
        A[i]--;
    }

    vector<ll> sum(N + 1, 0);
    rep(i, N) {
        sum[i + 1] += (sum[i] + A[i]) % K;
    }

    queue<ll> que;
    map<ll, ll> cnt;
    ll ans = 0;
    rep(i, N + 1) {
        que.push(sum[i]);
        ans += cnt[sum[i]]++;
        if ((int)que.size() >= K) {
            cnt[que.front()]--;
            que.pop();
        }
    }

    cout << ans << endl;
    return 0;
}