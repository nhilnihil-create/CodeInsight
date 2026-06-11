#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N, K;
    cin >> N >> K;
    if(K > (N-1)*(N-2)/2) {cout << -1 << endl; return 0;}
    vector<pii> ans;
    int cnt = ((N-1)*(N-2)/2)-K;
    cout << N-1+cnt << endl;
    rep2(i, 2, N){
        cout << 1 << ' ' << i << endl;
    }
    rep2(i, 2, N-1){
        rep2(j, i+1, N){
            if(cnt == 0) break;
            cout << i << ' ' << j << endl;
            cnt--;
        }
    }
}