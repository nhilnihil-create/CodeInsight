#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, V, P;
    cin >> N >> M >> V >> P;
    vector<ll> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    sort(all(A));
    reverse(all(A));
    int l = 0, r = N + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (mid <= P) {
            l = mid;
            continue;
        }
        if (A[mid - 1] + M < A[P - 1]) {
            r = mid;
            continue;
        }
        ll sum = M * (P + N - mid);
        rep(i, P - 1, mid - 1) {
            sum += min(M, A[mid - 1] + M - A[i]);
        }
        if (sum >= M * V) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}