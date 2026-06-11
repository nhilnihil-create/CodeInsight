#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
int mod = (int) 1e9 + 7;

int main(){
    
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n,0);
    int a[12][12] = {};
    
    rep(i,n){
        cin >> c[i];
        rep(j,m) cin >> a[i][j];
    }
    
    vector<int> b(m,0);
    
    rep(i,n) rep(j,m){
        b[j] += a[i][j];
    }

    int b_min = 100000;
    rep(j,m) b_min = min(b_min, b[j]);
    
    if(b_min < x){
        cout << -1 << "\n";
        return 0;
    }
    
    int max = (int)pow(2,n);
    int ans = 10000000;
    
    for(int i = 1; i <= max; i++){
        
        int t = i, count = 0, aa[12] = {};
        
        rep(j,n){
            if(t % 2 > 0){
                count += c[j];
                rep(k,m) aa[k] += a[j][k];
            }
            t /= 2;
        }
        
        int aa_min = 10000000;
        rep(k,m) aa_min = min(aa_min, aa[k]);
        
        if(aa_min < x) continue;
        
        ans = min(ans, count);
                
    }
    
    cout << ans << "\n";
    
    return 0;
}
