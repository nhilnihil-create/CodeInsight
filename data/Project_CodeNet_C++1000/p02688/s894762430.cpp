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
#define vl vector<ll>
#define vs vector<string>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int N, K;
    cin >> N >> K;
    vi X(N, 0);
    rep(i, K)
    {
        int d;
        cin >> d;
        rep(j, d)
        {
            int p;
            cin >> p;--p;
            X[p]++;
        }
    }
    int ans = 0;
    rep(i, N)
    {
        if(X[i] == 0) ++ans;
    }
    cout << ans << endl;
    return 0;
}