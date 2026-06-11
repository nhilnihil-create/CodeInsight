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


int main() {
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    rep(i, 0, n)cin >> a[i];
    rep(i, 0, k){
        vector<int>b(n+10, 0);
        rep(j, 0, n){
            int l = max(0, j-a[j]);
            int r = min(n-1, j+a[j]);
            b[l]++;
            b[r+1]--;
        }
        rep(j, 1, n){
            b[j] += b[j-1];
        }
        bool p = true;
        rep(j, 0, n){
            if(b[j]!=a[j])p = false;
            a[j] = b[j];
        }
        if(p)break;
    }
    rep(i, 0, n)cout << a[i] << " ";
    cout << endl;
}