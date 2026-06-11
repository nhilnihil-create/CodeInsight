#include <bits/stdc++.h>
#define MAXN 2010
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
using namespace std;
const ll mod = 1e9 + 7;

ll n, m, ps[MAXN][MAXN];

int main (){
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    vector<ll> a(n), b(m);

    ps[n][0] = ps[0][m] = 1;

    for (int i=0; i<n; i++){
        ps[i][0] = 1;
        cin >> a[i];
    }

    for (int i=0; i<m; i++){
        ps[0][i] = 1;
        cin >> b[i];
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            ps[i][j] = (ps[i-1][j] + ps[i][j-1])%mod;
            if (a[i-1] != b[j-1]){
                ps[i][j] = (ps[i][j] - ps[i-1][j-1] + mod)%mod;
            }
        }
    }

    cout << ps[n][m] << endl;
    return 0;
}