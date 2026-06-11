#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll N, K; cin >> N >> K;
    string S; cin >> S;
    ll unhappies = 0;
    rep(i, N - 1) {
        if (S[i] == 'R' && S[i + 1] == 'L') unhappies += 2;
    }
    if (S[0] == 'L') unhappies++;
    if (S[S.size()-1] == 'R') unhappies++;

    unhappies = unhappies - 2 * K <= 0 ? 1 : unhappies - 2 * K;
    cout << N - unhappies << endl;
    return 0;
}