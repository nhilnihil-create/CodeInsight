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
const int MOD = 1e9 + 7;
const int INF = 2e18;

signed main() {
    int N, M, V, P;
    cin >> N >> M >> V >> P;
    vector<int> A(N);
    cin >> A;
    sort(A.rbegin(), A.rend());
    int base = A[P - 1];
    int same = 0;
    int ans = P;
    int minus = 0;
    for (int i = P; i < N; i++) {
        if (base == A[i]) {
            same++;
            ans++;
            continue;
        }
        int count = (P - 1) + N - i;
        if (count >= V && base - A[i] <= M) ans++;
        else if (count < V) {
            int mid = i - (P - 1);
            int temp = V - (P - 1) - (N - i);
            temp = temp * M;
            temp -= minus;
            int check = 0;
            if (temp > 0) check = temp / mid + (temp % mid != 0);
            if (base + check - A[i] <= M) ans++;
        }
        minus += (base - A[i]);
    }
    cout << ans << endl;
}
