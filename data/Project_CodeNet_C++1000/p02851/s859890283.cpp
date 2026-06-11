#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
        A[i]--;
        A[i] %= K;
    }

    vector<int> sum(N+1);
    rep(i, N) sum[i+1] = (sum[i] + A[i]) % K;

    map<int, int> cnt;
    deque<int> dq;
    ll ans = 0;
    rep(i, N+1) {
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
        dq.push_back(sum[i]);
        while (K <= dq.size()) {
            cnt[dq.front()]--;
            dq.pop_front();
        }
    }

    cout << ans << endl;
}