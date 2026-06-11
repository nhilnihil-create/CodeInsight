#include<bits/stdc++.h>
/* #define int long long */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main(){
    int n;
    ll k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i], a[i]--;

    deque<int> roop;
    vector<bool>seen(n, false);
    int ans;
    int now = 0;

    while(true){
        if(seen[now]){
            while(roop[0] != now){
                k--;
                roop.pop_front();
                if(k == 0){
                    cout << roop[0]+1 << endl;
                    return 0;
                }
            }
            break;
        }
        roop.push_back(now);
        seen[now] = true;
        now = a[now];
    }

    cout << roop[k % roop.size()] + 1 << endl;
}