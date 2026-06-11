#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 998244353;
const int INF = 2e18;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    sort(A.begin(), A.end());
    int count = 0;
    vector<pair<int, int>> ans;
    for (int i = 0; i < N; i++) count += abs(A[i]);
    if (N == 2) {
        int minValue = min(A[0], A[1]);
        int maxValue = max(A[0], A[1]);
        cout << maxValue - minValue << endl;
        cout << maxValue << " " << minValue << endl;
        return 0;
    }

    if (A[0] > 0) {
        count -= abs(A[0]) * 2;
        int base = A[0] - A[1];
        ans.emplace_back(A[0], A[1]);
        for (int i = 2; i < N - 1; i++) {
            ans.emplace_back(base, A[i]);
            base -= A[i];
        }
        ans.emplace_back(A[N - 1], base);
    } else if (A[N - 1] < 0) {
        count -= abs(A[N - 1]) * 2;
        int base = A[N - 1] - A[N - 2];
        ans.emplace_back(A[N - 1], A[N - 2]);
        for (int i = N - 3; i > 0; i--) {
            ans.emplace_back(base, A[i]);
            base -= A[i];
        }
        ans.emplace_back(base, A[0]);
    } else {
        for (int i = 1; i < N - 1; i++) {
            if (A[i] > 0) continue;
            ans.emplace_back(A[N - 1], A[i]);
            A[N - 1] -= A[i];
        }
        for (int i = 1; i < N - 1; i++) {
            if (A[i] <= 0) continue;
            ans.emplace_back(A[0], A[i]);
            A[0] -= A[i];
        }
        ans.emplace_back(A[N - 1] , A[0]);
    }

    cout << count << endl;
    for (auto temp : ans) {
        cout << temp.first << " " << temp.second << endl;
    }
}
