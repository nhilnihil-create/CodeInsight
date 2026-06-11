#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define debug(var)  do{std::cout << #var << " : "; view(var);}while(0)
using namespace std;
typedef long long ll;
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){for(const auto& v : vv){ view(v); } }
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void viewarr(T arr[], int n) { for(int i = 0; i < n; ++i) std::cout << arr[i] << " "; std::cout << std::endl; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;

const int MAX_N = 50;
ll x[MAX_N];
ll y[MAX_N];

int main() {
    int N; cin >> N;
    rep(i,N) cin >> x[i] >> y[i];
    ll p, q;
    int ans = N;
    rep(i,N) {
        rep(j,N) {
            if(i <= j) continue;
            int cnt = 0;
            p = x[i] - x[j];
            q = y[i] - y[j];
            rep(k,N) rep(l,N) if(x[k]-p == x[l] && y[k]-q == y[l]) ++cnt;
            chmin(ans, N - cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
