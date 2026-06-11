#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,m; cin >> n >> m;
    if(n % 2) {
        rep(i,m) cout << 1+i << " " << n-1-i << endl;
        return 0;
    }
    int a = n/2-1;
    vector<vector<int>> ans(a);
    if(n%4 == 0) {
        rep(i,a/2) {
            ans[i].push_back(i+1);
            ans[i].push_back(n-1-i);
        }
        rep(i,a/2+1){
            ans[i+a/2].push_back(i+a/2+1);
            ans[i+a/2].push_back(n-2-a/2-i);
        }
    }else{
        rep(i,a){
            ans[i].push_back(i+1);
            ans[i].push_back(n-2-i);
        }
        rep(i,a/2) ans[i][1]++;
    }
    rep(i,m) cout << ans[i][0] << " " << ans[i][1] << endl;
}