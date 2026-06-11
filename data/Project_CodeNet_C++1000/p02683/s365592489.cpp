#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main(){
    int n,m,x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n,vector<int>(m));
    rep(i,n){
        cin >> c[i];
        rep(j,m) cin >> a[i][j];

    }
    bool bp = false;
    int ans = 1300000;
    for(int tmp = 0; tmp < (1 << 13); tmp++){
        bitset<13> s(tmp);
        vector<int> y(m,0);
        int sum = 0;
        rep(i,n){
            if(s.test(i)) sum += c[i];
            rep(j,m){
                if(s.test(i)) y[j] += a[i][j];
        }

        }
        bool check = true;
        rep(i,m){
            if(!(y[i] >= x)) check = false;
        
        }
        if(check){
            bp = true;
        ans = min(ans,sum);
        }
        

    }

    if(bp)cout << ans << endl;
    else cout << -1 << endl;
    
}

