#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<int> IntegerToVector(int bit, int N) {
    vector<int> S;
    for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) S.push_back(1);
        else S.push_back(0);
    }
    return S;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > list(n, vector<int>(n, -1));
    rep1(i, n){
        int a;
        cin >> a;
        rep1(j, a){
            int x, y;
            cin >> x >> y;
            x--;
            list[i][x] = y;
        }
    }
    ll ans = 0;
    for (int bit=0; bit<(1<<n); ++bit){
        vector<int> S = IntegerToVector(bit, n);
        ll cnt = 0;
        bool judge = true;
        rep1(i, n){
            if (S[i]==1) cnt++;
            rep1(j, n){
                if (S[i]==1) if ((list[i][j]==0 && S[j]==1) || (list[i][j]==1 && S[j]==0)) judge = false;
            }
        }
        if (judge) ans = max(ans, cnt);
    }
    cout << ans << endl;
    //printf("%.12f", ans);
}