
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << endl;
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

void z_algorithm(const string& s, vector<ll>& A) {
    A.resize(s.size(), 0);
    A[0] = s.size();

    int i = 1, j = 0;
    while(i < s.size()) {
        while(i + j < s.size() && s[i + j] == s[j]) ++j;
        A[i] = j;
        if (j == 0) {++i; continue;}
        int k = 1;
        while(i + k < s.size() && k + A[k] < j) A[i+k] = A[k], ++k;
        i += k; j -= k;
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    string S;

    cin >> N;
    cin >> S;

    ll ans = 0;
    REP(i, N) {
        string s = S.substr(i, S.size());
        vector<ll> A(s.size());

        z_algorithm(s, A);

        REP(j, A.size()) {
            if (j > A[j] - 1) ans = max(A[j], ans);
        }
    }

    print(ans);
}
