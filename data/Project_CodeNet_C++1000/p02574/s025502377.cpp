#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << ":" << #x << " = " << (x) << endl;
#else
#define dbg
#endif

#pragma endregion Macros


ll M = 1000000;
vector<ll> spf(M + 1);

void init() {
    for (int i = 0; i <= M; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= M; i++) {
        if (spf[i] != i) continue;
        for (int j = i * i; j <= M; j += i) {
            spf[j] = i;
        }
    }
}

set<ll> pf(ll n){
    set<ll> res;
    
    while(n!=1){
        res.insert(spf[n]);
        n /= spf[n];
    }

    return res;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    if(*max_element(A.begin(), A.end()) == 1){
        cout << "pairwise coprime";
        return 0;
    }

    init();

    vector<ll> c(M + 1);
    
    rep(i,N){
        auto s = pf(A[i]);
        for(auto x : s){
            c[x]++;
        }
    }

    string ans;

    ll max_cnt = *max_element(c.begin(), c.end());
    if (max_cnt == 1) {
        ans = "pairwise coprime";
    }else if(max_cnt == N){
        ans = "not coprime";
    }else{
        ans = "setwise coprime";
    }

    cout << ans << endl;
}
