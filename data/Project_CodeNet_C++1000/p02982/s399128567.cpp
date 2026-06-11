#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n, d;
    cin >> n >> d;
    
    vector<vector<double>> x(n,vector<double>(d));
    rep(i,n) rep(j,d) cin >> x[i][j];
    
    vector<int> dis;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int sum = 0;
            for(int k = 0; k < d; k++) {
                sum += (x[j][k] - x[i][k]) * (x[j][k] - x[i][k]);
            }
            dis.push_back(sum);
        }
    }
    
    int ans = 0;
    rep(i,dis.size()) {
        rep(j,10000) {
            if(dis[i] == j*j) {
                ans++;
                break;
            }
        }
    }
    
    cout << ans << endl;
    
    
    
    return 0;
}
