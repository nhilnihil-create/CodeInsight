#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

const int N = 100009, mod = 1000000007;
int n;
string s;

int fact(int x) {
    int ret = 1;
    while(x) {
        ret = (ret*x)%mod;
        x--;
    }
    return ret;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    vector<bool> left(2*n);
    left[0] = true;
    for(int i = 1; i < 2*n; ++i) {
        if(s[i] == s[i-1]) left[i] = !left[i-1];
        else left[i] = left[i-1];
    }

    int ans = 1;
    int lefts = 0, rights = 0;
    for(int i = 0; i < 2*n; ++i) {
        if(left[i]) {
            lefts++;
        } else {
            ans = (ans*(lefts-rights))%mod;
            rights++;
        }
    }

    if(rights != lefts || s[0] == 'W' || s[2*n-1] == 'W') ans = 0;
    else ans = (ans*fact(n))%mod;

    cout << ans << endl;
    
    return 0;
}
