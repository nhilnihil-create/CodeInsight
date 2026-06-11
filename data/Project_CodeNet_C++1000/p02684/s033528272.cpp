#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;
const ll MOD = 1e9 + 7;


int main(){
    ll n, k;
    cin >> n >> k;
    vector<int> G(n);
    rep(i, n){
        int a;
        cin >> a;
        G[i] = a-1;
    }

    vector<int> dist(n, INF);
    dist[0] = 0;
    int now = 0;
    int v, x, y;
    rep(i, n){
        if(dist[G[now]] != INF){
            v = G[now];
            x = dist[G[now]];
            y = dist[now]+1 - x;
            break;
        }
        dist[G[now]] = dist[now]+1;
        now = G[now];
    }

    if(k <= x){
        now = 0;
        rep(i, k) now = G[now];
    }
    else{
        now = v;
        rep(i, (k-x)%y) now = G[now];
    }

    cout << now+1 << endl;
}