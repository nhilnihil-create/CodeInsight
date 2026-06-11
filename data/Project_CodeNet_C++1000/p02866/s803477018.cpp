#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;
#define INF 1e+14

const ll MOD = 998244353;

ll modpow(ll n, ll a)
{
    if (a == 0)
        return 0;
    ll ans = 1;
    REP(i, n)
    {
        ans *= a;
        ans %= MOD;
    }
    return ans;
}

ll vec_max(vecl A) {
    sort(A.begin(),A.end());
    return A[A.size() - 1];
}

int main() {
    int N;
    cin >> N;
    vecl D(N);
    REP(i,N) cin >> D[i];
    REP(i, N)
    {
        if (i == 0 && D[i] != 0)
        {
            cout << 0 << endl;
            return 0;
        }
        if (i > 0 && D[i] == 0)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    if(D[0] != 0)
        cout << 0 << endl;
    else {
        ll ma = vec_max(D);
        map<ll,ll> mp;
        REP(i, N)
        if (mp.count(D[i])) mp[D[i]]++;
        else
            mp[D[i]] = 1;
        ll ans = 1;
        for(int i = 0; i < ma; i++) {
            if(!mp.count(i+1)) {
                cout << 0 << endl;
                return 0;
            }
            ans *= modpow(mp[i + 1], mp[i]);
            ans %= MOD;
        }
        cout << ans << endl;
    }
}
