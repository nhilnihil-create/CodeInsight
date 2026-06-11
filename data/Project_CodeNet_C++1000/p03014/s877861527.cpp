#include<bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (int i=0; i < n; i++)
#define repran(i, a,b) for (int i = a; i<b;i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using LP = pair<ll,ll>;
using P = pair<int,int>;
const ll inf = 1e9;


int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    vector<vector<int>> L(h, vector<int>(w, 0));
    vector<vector<int>> R(h, vector<int>(w, 0));
    vector<vector<int>> U(h, vector<int>(w, 0));
    vector<vector<int>> D(h, vector<int>(w, 0));
    rep(i, h) cin>> g[i];
    rep(i, h) rep(j, w){
        if (g[i][j]=='#') continue;
        if (i == 0) U[i][j] = 1;
        else U[i][j] = U[i-1][j]+1;
        if (j == 0) L[i][j] = 1;
        else L[i][j] = L[i][j-1]+1;
    }
    repd(i, h) repd(j, w){
        if (g[i][j]=='#') continue;
        if (i == h-1) D[i][j] = 1;
        else D[i][j] = D[i+1][j]+1;
        if (j == w-1) R[i][j] = 1;
        else R[i][j] = R[i][j+1]+1;
    }
    int ans = 0;
    rep(i, h) rep(j, w){
        int tmp = L[i][j]+R[i][j]+U[i][j]+D[i][j]-3;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    
}