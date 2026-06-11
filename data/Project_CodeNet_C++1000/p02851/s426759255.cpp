#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;
typedef long long ll;

int main() {

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i,N) {
        cin >> A[i];
        A[i]--;
        A[i] %= K;
    }
    vector<ll> S(N + 1);
    S[0] = 0;
    rep(i,N) S[i + 1] = (S[i] + A[i]) % K;

    map<int, int> m;

    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        if (i >= K) {
            m[S[i - K]]--;
            if (m[S[i - K]] == 0) m.erase(S[i - K]);
        }
        if (m.find(S[i]) == m.end()) m.emplace(S[i], 1);
        else {
            ans += m[S[i]];
            m[S[i]]++;
        }
    }

    cout << ans << endl;
    
    return 0;
}