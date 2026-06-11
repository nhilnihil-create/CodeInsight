#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            if(i % 2 != j % 2) cout << 1 << " ";
            else if(i % 4 != j % 4) cout << 2 << " ";
            else if(i % 8 != j % 8) cout << 3 << " ";
            else if(i % 16 != j % 16) cout << 4 << " ";
            else if(i % 32 != j % 32) cout << 5 << " ";
            else if(i % 64 != j % 64) cout << 6 << " ";
            else if(i % 128 != j % 128) cout << 7 << " ";
            else if(i % 256 != j % 256) cout << 8 << " ";
            else if(i % 512 != j % 512)cout << 9 << " ";
        }
        cout << endl;
    }
    return 0;
}