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

const int MAX_N = 100010;
ll A[MAX_N];

int main() {
    int N; cin >> N;
    rep(i,N) cin >> A[i];
    vector<pair<ll,ll>> ans;
    sort(A, A+N);
    int Q = 0;
    rep(i,N) {
        if(A[i] < 0) ++Q;
    }
    if(Q == 0) Q = 1;
    if(Q == N) Q = N - 1;
    for(int i = Q; i < N-1; ++i) {
        ans.push_back(make_pair(A[0], A[i]));
        A[0] = A[0] - A[i];
    }
    for(int i = 0; i < Q; ++i) {
        ans.push_back(make_pair(A[N-1], A[i]));
        A[N-1] = A[N-1] - A[i];
    }
    cout << A[N-1] << endl;
    for(const auto e : ans) cout << e.first << " " << e.second << endl;
    return 0;
}
