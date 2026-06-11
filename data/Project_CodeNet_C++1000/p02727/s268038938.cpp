#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    FastIO;
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> red(a), greeen(b), free(c);
    rep(i, a) cin >> red[i];
    rep(i, b) cin >> greeen[i];
    rep(i, c) cin >> free[i];

    sort(rall(red));
    sort(rall(greeen));
    sort(rall(free));
    int ri = x-1, gi = y-1;
    int i = 0;
    while(i < c){
        bool rOk = (ri >= 0), gOk = (gi >= 0);
        bool ch = false;
        if (rOk && gOk){
            if (red[ri] > greeen[gi]){
                if (greeen[gi] < free[i]){
                    ch = true;
                    greeen[gi] = free[i];
                    gi--;
                }
            }else{
                if (red[ri] < free[i]){
                    ch = true;
                    red[ri] = free[i];
                    ri--;
                }
            }
        }else if(rOk){
            if (red[ri] < free[i]){
                ch = true;
                red[ri] = free[i];
                ri--;
            }
        }else if(gOk){
            if (greeen[gi] < free[i]){
                ch = true;
                greeen[gi] = free[i];
                gi--;
            }
        }
        if (!ch) break;
        i++;
    }
    ll ans = 0;
    rep(i, x) ans += red[i];
    rep(i, y) ans += greeen[i];
    cout << ans << endl;
}