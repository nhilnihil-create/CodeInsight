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
#define mod 720720
#define yes cout << "Yes\n"
#define no cout << "No\n";
#define take for(auto &it : a) cin >> it;
#define out cout << a << "\n";
#define l_b lower_bound
#define u_b upper_bound
#define Max 100005
template<typename T> T mymax(T x, T y) {
    return (x > y ? x : y);
}

using namespace std;

const int N = 100005;
int cnt[N];
void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(q);
    take;
    for(int x : a) {
        cnt[x]++;
    }
    for(int i = 1; i <= n; i++) {
        int p = q - cnt[i];
        if(k - p <= 0) {
            no;
        }
        else yes;
    }
    return;
}

int main() {
    /*int tc;
    scanf("%d", &tc);
    while(tc-- > 0)*/
    solve();
    return 0;
}
