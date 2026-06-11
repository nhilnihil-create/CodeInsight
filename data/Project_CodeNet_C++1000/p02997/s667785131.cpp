#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11

int g[105][105];

int main()
{
    int n,k; cin >> n >> k;
    if(((n-1) * (n-2))/2 < k){
        cout << -1 << endl;
    }else{
        rep(i,n) rep(j,n) g[i][j] = false;
        rep(i,n){
            rep(j,n){
                if(i == j) continue;
                if(i == 0){
                    g[i][j] = true;
                    g[j][i] = true;
                }
            }
        }
        int cnt = ((n-1) * (n-2))/2;
        rep(i,n) rep(j,n){
            if(i != j && !g[i][j] && k < cnt){
                g[i][j] = true;
                g[j][i] = true;
                cnt--;
            }
        }
        cout << (n*(n-1))/2 - k << endl;
        rep(i,n){
            for(int j = i+1; j < n; j++){
                if(g[i][j]) cout << i+1 << ' ' << j+1 << endl;
            }
        }
    }
}