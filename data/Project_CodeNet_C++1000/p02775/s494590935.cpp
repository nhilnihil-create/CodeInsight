#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl

const int N = 1000003;
string s;
int n;

int d[N];
int ans = N*10;

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    n = s.length();

    for(int i = 1; i <= n; ++i) {
        d[i] = s[i-1] - '0';
    }

    int i = n;
    while(i > 0) {
        if(d[i] >= 5) {
            d[i] = 10-d[i];
            int len = 1;
            while(i-len > 0 && d[i-len] >= 5) {
                d[i-len] = 9-d[i-len];
                len++;
            }
            if(len > 1 || d[i] < 5)
                d[i-len]++;
            i -= len;
        } else {
            i--;
        }
    }
    
    long long ans = 0LL;
    for(int i = 0; i <= n; ++i) {
        ans += min(d[i], 10-d[i]);
    }

    cout << ans << endl;
    
    return 0;
}

