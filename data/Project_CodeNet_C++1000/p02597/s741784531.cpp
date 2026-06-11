#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt_w = 0;
    int out = 0;
    rep(i, n) {
        if (s[i]=='W') cnt_w++;
    }
    for (int i = n-1; i >= n-cnt_w; i--) {
        if (s[i]=='R') out++;
    }
    cout << out << endl;
    return 0;
}