#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<ll, ll> P;
int main()
{
    
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<P> order(N - 1);
    int p = 0, m = 0;
    ll ans = 0;

    rep(i, N) {
        cin >> A[i];
        if (A[i] >= 0) p++;
        else m++;
    }
    sort(all(A));

    if (m == 0) {
        ll right = A[0];
        for (int i = N - 1; i >= 2; i--) {
            order[N - i - 1] = P(right, A[i]);
            right -= A[i];
        }
        order[N - 2] = P(A[1], right);
        ans = A[1] - right;
    }
    else if (p == 0) {
        ll left = A[N - 1];
        for (int i = 1; i < N - 1; i++) {
            order[i - 1] = P(left, A[i]);
            left -= A[i];
        }
        order[N - 2] = P(left, A[0]);
        ans = left - A[0];
    }
    else {
        ll right = A[0];
        ll left_i = N - 1;
        int cnt = 0;
        for (int i = N - 1; i >= 0; i--) {
            left_i = i;
            if (p <= 1) break;
            order[cnt] = P(right, A[i]);
            right -= A[i];
            cnt++;
            p--;
        }
        order[cnt] = P(A[left_i], right);
        cnt++;
        ans = A[left_i] - right;
        for (int i = 1; i < left_i; i++) {
            order[cnt] = P(ans, A[i]);
            ans -= A[i];
            cnt++;
        }
    }

    cout << ans << endl;
    rep(i, N - 1) {
        cout << order[i].first << " " << order[i].second << endl;
    }

    return 0;
}