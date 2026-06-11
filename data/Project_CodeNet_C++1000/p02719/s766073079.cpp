#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
using namespace std;
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using ll = long long;
using P  = pair<int, int>;
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    ll N, K;
    cin >> N >> K;
    if(N < K && N < K-N) {
        cout << N << endl;return 0;
    }
    if(N%K == 0)
    {
        cout << 0 << endl;return 0;
    }

    ll x = N%K;
    ll ans = INF;
    int cnt = 0;
    while(1)
    {
        x = abs(x-K);
        if(!chmin(ans, x)) ++cnt;
        if(cnt > 100) break;
    }
    cout << ans << endl;
    return 0;
}