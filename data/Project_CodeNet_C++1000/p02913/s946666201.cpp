#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    int ans = 0;
    string S; cin >> S;
    rep(l, N) {
        string s = S.substr(l, S.size());
        vector<int> Z(N - l);
        Z[0] = N - l;
        int i = 1, j = 0;
        while(i < s.size()) {
            while(i + j < N && j < s.size() && s[j] == s[i + j]) ++j;
            Z[i] = j;
            if(j == 0) {
                ++i;
                continue;
            }
            int k = 1;
            while(k < j && k + Z[k] < j) {
                Z[i + k] = Z[k];
                ++k;
            }
            i += k;
            j -= k;
        }
        rep(k, N - l) {
            if(Z[k] <= k) {
                ans = max(ans, Z[k]);
            }
        }
    }
    cout << ans << endl;
}
