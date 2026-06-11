#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
using namespace std;
typedef pair<int, int> P;

const int INF = 1e13;

int n, m;
int d[110][110];

void init(int n){
    rep(i, 0, n){
        rep(j, 0, n){
            d[i][j] = INF;
            if(i == j) d[i][j] = 0;
        }
    }
}

void warshall_floyd(){
    rep(k, 0, n){
        rep(i, 0, n){
            rep(j, 0, n){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

signed main(){
    cin >> n >> m;
    init(n);
    rep(i, 0, m){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;    
    }
    warshall_floyd();
    rep(i, 0, n){
        if(d[i][i] != 0){
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    rep(i, 0, n){
        rep(j, 0, n){
            if(j != 0) cout << " ";
            if(d[i][j] >= 1e10) cout << "INF";
            else cout << d[i][j];
        }
        cout << endl;
    }
}