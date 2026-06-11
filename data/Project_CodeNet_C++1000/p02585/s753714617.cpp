#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  // i<4:4way i<8:8way
int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll n,k,ans = -1e18;
    cin >> n >> k;

    vector<ll> p(n+1),c(n+1);
    for(int i=1;i<=n;i++)cin >> p[i];
    rep(i,n)cin >> c[i+1];
    for(int i=1;i<=n;i++){
        // i は開始地点
        vector<bool> v(n+1,false); // 訪れたかどうか
        ll tmp = 0;
        int len = 0;
        int left = 0;
        int now = i;
        v[now] = true;
        for(int j=0;j<k;j++){
            now = p[now];
            tmp += c[now];
            len++;
            chmax(ans,tmp);
            if(v[now]){
                left = k - j - 1; // 残りの操作回数は k - j - 1 回になる
                break;
            }
        }
        if(left){
            // ループの長さはlen
            // 1ループあたりのスコアはtmp
            // よってtmp *= (k/len)
            int x = k/len;
            if(x)x--;
            tmp = tmp * x;
            left %= len;
            for(int j=0;j<left + len;j++){
                now = p[now];
                tmp += c[now];
                chmax(ans,tmp);
            }
        }
    }
    cout << ans << endl;
}