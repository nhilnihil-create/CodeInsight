#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

// k回2倍 -> bit演算を使うと便利
int main() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                int x = a * (1 << i);
                int y = b * (1 << j);
                int z = c * (1 << k);
                if(i + j + k <= n && x < y && y < z){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}