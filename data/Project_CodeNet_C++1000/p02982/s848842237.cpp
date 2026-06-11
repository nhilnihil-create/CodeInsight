#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    int n, d; cin >> n >> d;
    vector<vector<int>> vec(n);
    rep(i, n){
        vec[i].resize(d);
        rep(j, d) cin >> vec[i][j];
    }
    int ans = 0;
    rep(i, n){
        for (int j = i; j < n; j++){
            if (i == j) continue;
            double dist = 0;
            rep(k, d){
                dist += pow(abs(vec[i][k] - vec[j][k]), 2); 
            }
            double sqrt_dist = (double)sqrt(dist);
            if (pow((int)sqrt_dist, 2) == dist) ans ++;
        }
    }
    cout << ans << endl;
}