#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
//const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = unsigned long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1000000000000000000;
int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)cin >> A[i];
    sort(ALL(A));
    if(*A.begin() == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if(*A.rbegin() > INF)
    {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 1;
    rep(i, N) {
        if(A[i] > INF/ans)
        {
            cout << -1 << endl;
            return 0;
        }
        ans *=A[i];
        if(ans > INF) 
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
