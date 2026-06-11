#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    vector<vector<pii>>xy(n);
    rep(i, 0, n){
        int a;
        cin >> a;
        rep(j, 0, a){
            int b, c;
            cin >> b >> c;
            b--;
            xy[i].push_back(pii(b, c));
        }
    }
    for(int bit=0; bit<(1<<n); bit++){
        bool p = true;
        rep(i, 0, n){
            //i人目検証
            if(!(bit&(1<<i)))continue;
            int m = xy[i].size();
            rep(j, 0, m){
                if(xy[i][j].second==1&& !(bit&(1<<(xy[i][j].first))))p = false;
                if(xy[i][j].second==0&& (bit&(1<<(xy[i][j].first))))p = false;
            }
        }
        if(p){
            int cnt = 0;
            rep(i, 0, n){
                if(bit&(1<<i))cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}