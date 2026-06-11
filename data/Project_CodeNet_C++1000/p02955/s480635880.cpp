#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
const ll INF = 1e14;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll N, K;
    cin >> N >> K;
    vl A(N);
    rep(i, N) cin >> A[i];
    ll sum = accumulate(all(A), 0ll);

    vl divl;
    repe(i,1,sqrt(sum)){
        if(sum%i==0){
            divl.eb(i);
            divl.eb(sum / i);
        }    
    }
    if (sum % (ll)sqrt(sum) == 0) divl.eb(sum / (ll)sqrt(sum));
    sort(all(divl));

    ll ans = INF;
    for(auto d: divl){
        vl R(N);
        rep(i, N) R[i] = A[i] % d;
        sort(all(R));
        ll DRsum = d*R.size()-accumulate(all(R), 0ll);

        ll m = 0;
        rep(i,N){
            m += R[i];
            DRsum += R[i] - d;
            // cout << d << " " << m << " " << DRsum << endl;
            if(max(m,DRsum)<=K){
                ans = d;
                break;
            }
        }
    }
    cout << ans << endl;
}