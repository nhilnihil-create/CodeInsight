#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;

signed main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        int ans = 0;
        rep(i, 1, 1001){
            rep(j, 2, 100){
                int sum = i * j + j * (j - 1) / 2;
                if(sum == n) ans++;
            }
        }
        cout << ans << endl;
    }
}