#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int A,B;
    cin >> A >> B;
    int X = __gcd(A,B);
    int Y = X;
    int ans = 1;
    for(int i = 2; i*i <= X; i++) {
        if(Y%i == 0) {
            while(Y%i == 0) {
                Y/=i;
            }
            ans++;
        }
    }
    if(Y != 1) {
        ans++;
    }
    cout << ans << endl;
}