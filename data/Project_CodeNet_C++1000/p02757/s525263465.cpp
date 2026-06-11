#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e3 + 5;
string s;
int n , p;
ll ans;
map<int , int> mp;
int main() {
    abdelrahman010
    cin >> n >> p >> s;
    int acc = 0;
    if(p == 2 || p == 5) {
        for(int i = n - 1;i >= 0;i--) {
            if((s[i] - '0') % p == 0)
                acc++;
            ans += acc;
        }
    } else {
        mp[0]++;
        int  pw = 1;
        for(int i = n - 1;i >= 0;i--) {
            acc = (acc + (1ll * pw * (s[i] - '0')) % p) % p;
            pw = (10ll * pw) % p;
            ans += mp[acc]++;
        }
    }
    cout << ans;
    return 0;
}