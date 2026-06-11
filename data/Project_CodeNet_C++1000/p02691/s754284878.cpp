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
using LP  = pair<ll, int>;
int main()
{
    int N;
    cin >> N;
    vl A(N);
    vector<LP> B;
    rep(i, N) {
        cin >> A[i];
        B.eb(LP(A[i] +i, i));
    }
    map<ll, int> m;
    ll ans = 0;
    rep(i, N)
    {
        ll a = A[i] + i;
        ll b = i - A[i];
        m[a]++;
        ans += m[b];
        
    }
    //  sort(ALL(B));
    // vl C(N);
    // rep(i, N) C[i] = B[i].first;
    // // |j-i| = ai + aj
    // // j = (ai+i) + aj 
    // ll ans = 0;
    // rep2(j, 2, N)
    // {
    //     ll x = j-A[j];
    //     if(x < 2) continue;
    //     auto p = lower_bound(ALL(C), x);
    //     while(p != C.end()){
    //        //if(B[p-C.begin()].second != j ) {
    //             if(*p == x) ++ans;
    //             else break;
    //         //}
    //         ++p;
    //     }
    // }
    cout << ans << endl;
    return 0;
}