#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<class U, class V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}

const int MAXN = 2e5 + 5;
int N;
int A[MAXN], B[MAXN];

int main() {
    FAST_IO();
    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    priority_queue<pii, vector<pii>, less<pii>> PQ;
    rep(i, N) {
        if(B[i] > A[i]) PQ.push({B[i] - A[i], i});
    }
    ll cnt = 0;
    while(!PQ.empty()) {
        int i = PQ.top().second; PQ.pop();
        if(B[i] - A[i] >= B[(i - 1 + N) % N] + B[(i + 1) % N]) {
            cnt += (B[i] - A[i]) / (B[(i - 1 + N) % N] + B[(i + 1) % N]);
            B[i] = (B[i] - A[i]) % (B[(i - 1 + N) % N] + B[(i + 1) % N]) + A[i];
            if(B[i] > A[i]) PQ.push({B[i] - A[i], i});
        } else {
            cout << "-1\n";
            return 0;
        }
    }
    cout << cnt << "\n";
}