#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    int ans = 0;
    rep(i,n) rep(j,d) cin >> x[i][j];
    rep(i,n) for(int j = i + 1; j < n; j++){
        int dist = 0;
        rep(k,d) dist += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
        rep(k,150) if(k*k == dist) ans++;
    }
    cout << ans << endl;
}