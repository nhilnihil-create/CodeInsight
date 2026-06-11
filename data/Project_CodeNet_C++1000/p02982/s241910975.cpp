#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n,d;
    cin >> n >> d;
    vector<vector<int>> x(n,vector<int>(d));
    rep(i,n) rep(j,d) cin >> x.at(i).at(j);
    int ans =0;
    for(int i = 0; i < n;i++){
        for(int j = i+1; j < n;j++){
            int dis = 0;
            rep(k,d) {
                dis += pow(x.at(i).at(k)-x.at(j).at(k),2);
            }
            int sq = sqrt(dis);
            if(dis == sq*sq) ans++;
        }
    }
    cout << ans << endl;
}