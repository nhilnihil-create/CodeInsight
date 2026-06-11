#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;

int main(){
    int n, m, x; cin >> n >> m >> x;
    int c[n], a[n][m];
    rep(i, n){
        cin >> c[i];
        rep(j, m) cin >> a[i][j];
    }
    int min_cost = 10000000;
    for(int i=0; i<1<<n; i++){
        int cost = 0;
        vector<int> rikai(m, 0);
        rep(j, n){
            if(i & 1<<j){
                rep(k, m) rikai[k] += a[j][k];
                cost += c[j];
            }
        }
        bool ok = true;
        rep(j, m){
            //cout << rikai[j] << " ";
            if(rikai[j] < x) ok = false;
        }
        //cout << "cost="<<cost<<endl;
        if(ok) min_cost = min(min_cost, cost);
    }
    if(min_cost == 10000000) cout << -1 << endl;
    else cout << min_cost << endl;
}