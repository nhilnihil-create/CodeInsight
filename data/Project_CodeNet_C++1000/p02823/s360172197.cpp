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
//#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    ll N, A, B; cin >> N >> A >> B;
    ll ans = 0;
    if(B > A) swap(A, B);
    if((A - B) % 2 != 0) {
        if(A - 1 > N - B) {
            ans += N - A + 1;
            B += N - A + 1;
            A = N;
        } else {
            ans += B;
            A -= B;
            B = 1;
        }
    }
    ans += (A - B) / 2;
    cout << ans << endl;
}
