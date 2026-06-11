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

const int N = 1e6 + 5;

void solve() {
    int mul;
    cin >> mul;
    bool was[N];
    memset(was, 0, sizeof(was));
    int m = 0, ans = 1;
    while(true) {
        m *= 10;
        m += 7;
        m %= mul;
        if(m == 0) {
            printf("%d\n", ans); return;
        }
        if(was[m]) {
            printf("-1"); return;
        }
        ans++;
        was[m] = 1;
    }
    return;
}

int main() {

    solve();
    return 0;
}
