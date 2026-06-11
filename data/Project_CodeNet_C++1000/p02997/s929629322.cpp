#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
    int n, k; cin >> n >> k;
    int ma = (n-1)*(n-2) / 2;
    if(k > ma) cout << -1 << ln;
    else{
        vector<pii> edges;
        for(int i=1; i<n; i++) edges.emplace_back(i, n);

        int cnt = 0;
        for(int i=1; i<n-1; i++){
            for(int j=i+1; j<=n-1; j++){
                if(cnt == ma - k)break;
                edges.emplace_back(i, j);
                cnt++;
            }
        }
        cout << edges.size() << ln;
        for(auto e: edges) cout << e.first << " " << e.second << ln;
    }
}