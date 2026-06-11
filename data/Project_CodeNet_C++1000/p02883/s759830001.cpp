#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
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
//1 2 4<-変化 ならすべき？ それとも，0をつくるべき？
//1000000 1 2
//3 2 1
const int MAX_N = 1e6 + 1;
ll N;
ll K;
ll A[MAX_N], F[MAX_N];

ll myceil(ll x, ll y) {//x / y
    if(x <= 0) return 0;
    return (x + (y - x % y) * (x % y != 0)) / y;
}

bool isAllUnder(ll x) { //K回の操作で最大値をx以下にできる？
    ll cnt = 0;
    for(ll i = 0; i < N; ++i) {
        ll a = A[i] * F[i];
        cnt += myceil(a - x, F[i]);
    }
    return cnt <= K;
}
int main() {
    cin >> N >> K;
    rep(i, N) {
        cin >> A[i];
    }
    sort(A, A + N);
    rep(i, N) {
        cin >> F[i];
    }
    sort(F, F + N, greater<ll>());
    ll ng = -1, ok = 1e18 + 1;
    while(ng + 1 < ok) {
        ll mid = (ng + ok) / 2;
        if(isAllUnder(mid)) {
            ok = mid;
        }else {
            ng = mid;
        }
    }
    cout << ok << endl;
    //ボトルネックがスコアに
    //A[i] * F[j] A[i]側をへらす
}
