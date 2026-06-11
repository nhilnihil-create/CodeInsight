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
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rnr(i,a,b) for(int i=int(a);i>=int(b);i--)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N, K, C; cin >> N >> K >> C;
    string S; cin >> S;
    int l[N + 1], r[N + 1];
    l[0] = 0;
    r[N] = 0;
    rep(i, N) {
        if(S[i] == 'x') {
            l[i + 1] = l[i];
        }else {
            if(i - C < 0) {
                l[i + 1] = 1;
            } else {
                l[i + 1] = l[i - C] + 1;
            }
        }
    }
    for(int i = N - 1; i >= 0; --i) {
        if(S[i] == 'x') {
            r[i] = r[i + 1];
        }else {
            if(i + C + 1 > N) {
                r[i] = 1;
            }else {
                r[i] = r[i + C + 1] + 1;
            }
        }
    }
    vector<int> ans;
    rep(i, N) {
        if(S[i] == 'o'){
            if(l[i] + r[i + 1] < K) {
                ans.pb(i + 1);
            }
        }
    }
    for(int v : ans) {
        cout << v << endl;
    }
}
