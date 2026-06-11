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

#pragma endregion Macros

int main()
{
    int N;
    cin >> N;
    vector<ll> A(N + 1);
    rep(i, N) cin >> A[i + 1];

    map<int, int> m;

    for(int j=1;j<=N;j++){
        int x = j - A[j];
        if(x >= 0) m[j - A[j]]++;
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        int x = i + A[i];
        ans += m[x];
    }
    cout << ans << endl;
}
