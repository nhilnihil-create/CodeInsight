#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
typedef long long int ll;

int main() {
        int k, ans;
        ans = -1;
        cin >> k;
        int sevens = 7%k;
        rep(i,k) {
                if (sevens % k == 0) {
                        ans = i+1;
                        break;
                }
                sevens *= 10;
                sevens += 7;
                sevens %= k;
        }
        cout << ans << endl;
}