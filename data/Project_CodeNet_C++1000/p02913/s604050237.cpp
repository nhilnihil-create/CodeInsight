
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
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
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


struct Z{
    vi a;
    Z() {}
    Z(string& s) : a(s.size()) {
        int n = s.size();
        a[0] = n;

        int i = 1, j = 0;
        while(i < n) {
            while(i + j < n && s[i + j] == s[j]) ++j;
            a[i] = j;
            if (j == 0) {++i; continue;}
            int k = 1;
            while(i + k < s.size() && k + a[k] < j) a[i+k] = a[k], ++k;
            i += k; j -= k;
        }
    }

    inline int operator[](int i) {return a[i];}
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    string S;

    cin >> N >> S;

    int ans = 0;
    REP(i, N) {
        string t(S.begin() + i, S.end());

        Z z(t);

        REP(j, t.size()) {
            if (j >= z[j]) ans = max(ans, z[j]);
        }
    }

    print(ans);

}
