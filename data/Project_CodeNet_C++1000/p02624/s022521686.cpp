
/*Allah vorosha*/
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
#define uniq(v)			v.resize(distance(v.begin(),unique(v.begin(),v.end())))
#define all(x) (x).begin(),(x).end()
#define pof pop_front
#define ios ios_base::sync_with_stdio(0);cin.tie();cout.tie();
#define scn scanf
#define prt printf
#define rep(i, a, n) for(int i = a; i < n; i++)
#define mod 1000000007
#define yes cout << "Yes\n"
#define no cout << "No\n";
#define take for(auto &it : a) cin >> it;
#define out cout << a << "\n";
#define l_b lower_bound
#define u_b upper_bound
#define f first
#define s second
#define Max 1005

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll num = (ll)n / i;
        num *= (num + 1);
        num /= 2;
        num *= i;
        ans += num;
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}
