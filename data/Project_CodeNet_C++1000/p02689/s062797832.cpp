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
using Graph = vector<vector<int>>;
int main()
{
    int N, M;
    cin >> N >> M;
    vl H(N);
    rep(i, N) cin >> H[i];
    vl B(N, -1);
    rep(i, M)
    {
        int a, b;
        cin >> a >> b;
        --a;--b;
        chmax(B[a], H[b]);
        chmax(B[b], H[a]);
    }
    int ans = 0;
    rep(i, N){
        if(H[i] > B[i]) ++ans;
    }
    cout << ans << endl;

    return 0;
}