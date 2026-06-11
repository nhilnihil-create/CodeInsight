#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    if(abs(a - b) % 2 == 0) {
        ans += abs(a - b) / 2;
    } else {
        ans += min(a - 1, n - b);
        if(a - ans == 1) {
            a = 1;
            b -= ans;
            b++;
        } else if(b + ans == n) {
            b = n;
            a += ans;
            a--;
        }
        ans += abs(a - b) / 2;
    }
    cout << ans << endl;
    return 0;
}