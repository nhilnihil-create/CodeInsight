#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i ++)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

int main() {
    int N; cin >> N;
    vector<P> A(N);
    rep(i,N) {
        int p; cin >> p;
        A[i] = P(p,i);
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());

    ll ans = 0;
    set<int> st = {-1,N};
    rep(i,N) {
        int a = A[i].first,j = A[i].second;
        int left1 = *(--st.lower_bound(j));
        int right1 = *st.lower_bound(j);
        //printf("a: %d, j: %d, left1: %d, right1 %d\n",a,j,left1,right1);
        if (left1 >= 0) {
            int left2 = *(--st.lower_bound(left1));
            ans += (ll)a*(left1 - left2)*(right1 - j);
        }
        if (right1 < N) {
            int right2 = *st.lower_bound(right1 + 1);
            ans += (ll)a*(right2 - right1)*(j - left1);
        }
        //printf("ans: %ld\n",ans);
        st.insert(j);
    }
    cout << ans << endl;
    return 0;
}