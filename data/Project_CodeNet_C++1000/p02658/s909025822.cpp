#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1000000000;

int main() {
    ll N;
    cin >> N;
    vector<ll>A(N);
    for (int i=0; i<N; i++)cin >> A[i];
    for (int i=0; i<N; i++){
        if (A[i] == 0){
            cout << 0 << endl;
            exit(0);
        }
    }

    ll ans = 1;
    for (int i=0; i<N; i++){
        ll emer = INF*INF / ans + 1; //A_iがemer以上だと答えが10^18を超えることになる
        ans *= A[i];
        if (ans > INF*INF || A[i] > emer){
            cout << -1 << endl;
            exit(0);
        }
    }
    cout << ans << endl;
}