#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll C[2010][2010];
ll mod = 1e9+7;
void init(){
    C[0][0] = 1;
    C[1][0] = 1;
    C[1][1] = 1;
    for(int i=2; i<2010; ++i){
        C[i][0] = 1;
        for(int j=1; j<2010; ++j){
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
        }
    }
}
int main() {
    init();
    int n, k;
    cin >> n >> k;
    int b = k;
    int r = n-k;
    for(int i=1; i<=k; ++i){
        ll prob = (C[r+1][i]*C[b-1][i-1])%mod;
        cout << prob << endl;
    }
}