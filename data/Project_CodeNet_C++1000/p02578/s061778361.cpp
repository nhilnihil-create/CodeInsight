/*Allah Vorosha*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define n_p next_permutation
#define p_p prev_permutation
#define in insert
#define rev reverse
#define pf push_front
#define pob pop_back
#define uniq(v)         v.resize(distance(v.begin(),unique(v.begin(),v.end())))
#define all(x) (x).begin(),(x).end()
#define pof pop_front
#define ios ios_base::sync_with_stdio(0);cin.tie();cout.tie();
#define scn scanf
#define prt printf
#define rep(i, a, n) for(int i = a; i < n; i++)
#define mod 1000000007
#define yes cout << "YES\n"
#define no cout << "NO\n";
#define take for(auto &it : a) cin >> it;
#define out cout << a << "\n";
#define l_b lower_bound
#define u_b upper_bound
#define Max 100005
template<typename T> T mymax(T x, T y) {
    return (x > y ? x : y);
}

using namespace std;

const int N = 2e5 + 5;
int n;
vector<int> a;
int dp[N][3];

int myfucn(int i, int t) {
    if(i >= n) return 0;
    if(dp[i][t] != -1) return dp[i][t];
    int ret;
    if(t) {
        ret = myfucn(i + 1, 0);
        ret = min(ret, myfucn(i + 2, 0));
    }
    else {
        ret = myfucn(i + 1, 1) + (a[i] == 1);
        int o = 0;
        if(i + 1 < n) o = a[i + 1];
        ret = min(ret, myfucn(i + 2, 1) + (a[i] == 1) + o);
    }
    dp[i][t] = ret;
    return ret;
}
void solve() {
    scanf("%d", &n);
    a.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i - 1]) {
            ans += ((ll)a[i - 1] - a[i]);
            a[i] = a[i - 1];
        }
    }
    printf("%lld\n", ans);
    return;
}

int main() {

    solve();
    return 0;
}
