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
    int n, m;
    cin >> n >> m;
    map<int, int> sc;
    rep(i, m){
        int s, c;
        cin >> s >> c;
        s = n - s + 1;
        if (sc.count(s) != 0 && sc[s] != c){
            cout << -1 << endl;
            return 0;
        }
        sc[s] = c;
    }

    if (sc.count(n) == 1 && sc[n] == 0 && n != 1){
        cout << -1 << endl;
        return 0;
    }

    if (m == 0 && n == 1){
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    for(int i = n; i > 0; i--){
        int val;
        if (sc.count(i) != 0){
            val = sc[i];
        }
        else{
            if (i == n){
                val = 1;
            }else{
                val = 0;
            }
        }
        for(int j = 1; j < i; j++){
            val *= 10;
        }
        ans += val;
    }
    cout << ans << endl;
}