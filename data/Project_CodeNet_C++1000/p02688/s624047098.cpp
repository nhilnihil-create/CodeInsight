#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    int n, k;
    cin >> n >> k;
    int d[k];
    int a[k][n];
    rep(i, k){
        cin >> d[i];
        rep(j, d[i]){
            cin >> a[i][j];
        }
    }
    
    int c[n];
    rep(i, n){c[i] =0;}
    rep(i, k){
        rep(j, d[i]){
            ++c[a[i][j]-1];
        }
    }
    
    int ans = 0;
    rep(i, n){
        if(c[i] == 0){++ans;}
    }
    
    cout << ans << endl;
    return 0;
}