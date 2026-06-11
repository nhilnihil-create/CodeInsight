#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    int n,m; cin >> n >> m;
    int f[n][m];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int a; cin >> a;
            f[i][j] = a;
        }
    }
    int ans = 0;
    
    for(int i = 0;i < n-1;i++){
        for(int j = i+1;j < n;j++){
            int total = 0;
            for(int k = 0;k < m;k++){
                //cout << abs(f[i][k]-f[j][k]);
                total += pow(abs(f[i][k]-f[j][k]),2);
            }
            double total2 = sqrt(total);
            if(floor(total2) == total2) ans++;
        }
    }
    cout << ans;
}
