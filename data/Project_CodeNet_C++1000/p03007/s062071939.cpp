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
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    int A[N];
    rep(i, N) {
        cin >> A[i];
    }
    sort(A, A + N);
    int posPlus = -1;
    rep(i, N) {
        if(A[i] > 0) {
            posPlus = i;
            break;
        }
    }
    if(posPlus == 0) {//plus only
        vector<Pint> ans;
        rep(i, N - 2) {
            ans.pb(mp(A[i], A[i + 1]));
            A[i + 1] = A[i] - A[i + 1];
        }
        ans.pb(mp(A[N - 1], A[N - 2]));
        cout << A[N - 1] - A[N - 2] << endl;
        rep(i, N - 1)
            cout << ans[i].first << ' ' << ans[i].second << endl;
    }else if(posPlus == -1) { //minusonly
        vector<Pint> ans;
        rep(i, N - 1) {
            ans.pb(mp(A[N - 1], A[i]));
            A[N - 1] = A[N - 1] - A[i];
        }
        cout << A[N - 1] << endl;
        rep(i, N - 1)
            cout << ans[i].first << ' ' << ans[i].second << endl;
    }else {
        vector<Pint> ans;
        for(int i = posPlus - 1; i < N - 2; ++i) {
            ans.pb(mp(A[i], A[i + 1]));
            A[i + 1] = A[i] - A[i + 1];
            A[i] = INF;
        }

        rep(i, N - 1) {
            if(A[i] == INF) continue;
            ans.pb(mp(A[N - 1], A[i]));
            A[N - 1] = A[N - 1] - A[i];
        }
        cout << A[N - 1] << endl;
        rep(i, N - 1)
            cout << ans[i].first << ' ' << ans[i].second << endl;
    }
}
