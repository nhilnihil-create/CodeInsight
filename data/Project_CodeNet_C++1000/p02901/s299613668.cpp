#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e3 + 5;
int n , m , all , a[N] , b[N];
int memo[N][1 << 13];
int solve(int i , int mask) {
    if(i == m)
        return (mask == (1 << n) - 1) ? 0 : 1e9;
    int &ans = memo[i][mask];
    if(~ans)
        return ans;
    return ans = min(solve(i + 1 , mask | b[i]) + a[i] , solve(i + 1 , mask));
}
int main() {
    abdelrahman010
    cin >> n >> m;
    for(int i = 0;i < m;i++) {
        int x , y;
        cin >> a[i] >> x;
        while(x--) {
            cin >> y;
            y--;
            b[i] |= (1 << y);
        }
        all |= b[i];
    }
    if(all != (1 << n) - 1)
        return cout << -1 , 0;
    memset(memo , -1 , sizeof memo);
    cout << solve(0 , 0);
    return 0;
}