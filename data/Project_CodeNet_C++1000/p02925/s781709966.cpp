#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i,n) rep(j,n-1){
        cin >> a[i][j];
        a[i][j]--;
    } 

    int ans = 0;
    while(true){
        int mnx = 1001;
        rep(i,n) mnx = min(mnx, a[i][n-1]);
        if (mnx == n-1) break;

        set<P> st;
        rep(i,n){
            if (a[i][n-1] == n-1) continue;
            int j = a[i][a[i][n-1]];
            if (a[j][n-1] == n-1) continue;
            int k = a[j][a[j][n-1]];
            if (i == k) st.insert(make_pair(min(i,j), max(i,j)));
        }

        if (st.size() == 0){
            cout << -1 << endl;
            return 0;
        }

        for(auto p : st){
            int i = p.first, j = p.second;
            a[i][n-1]++;
            a[j][n-1]++;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}