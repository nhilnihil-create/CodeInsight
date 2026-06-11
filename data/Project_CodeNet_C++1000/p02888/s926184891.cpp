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
    vector<int> L(N);
    rep(i, N) cin >> L[i];

    sort(all(L));

    ll ans = 0;
    rep(i, N) {
        repd(j, i + 1, N - 1) {
            int bam = L[j] - L[i], bap = L[j] + L[i];
            int indexd = upper_bound(all(L), bam) - L.begin();
            int indexu = lower_bound(all(L), bap) - L.begin();
            indexu--;
            if (indexu <= j || indexd >= indexu) continue;
            // cout << i << " " << j << " " << indexd << " " << indexu << endl;
            ans += max(0, indexu - j);
        }
    }

    cout << ans << endl;
    return 0;
}