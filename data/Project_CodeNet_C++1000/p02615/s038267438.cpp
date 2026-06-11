#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    //二分木
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    // sort(A.begin(), A.end());
    // reverse(A.begin(), A.end());
    sort(A.rbegin(), A.rend());//リバースイテレータ
    ll ans = 0;
    int t = N-1;
    rep(i, N)
    {
        int lim = 2;
        if(i == 0) lim = 1;
        rep(j, lim)
        {
            if(t > 0)
            {
                ans += A[i];
                t--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}