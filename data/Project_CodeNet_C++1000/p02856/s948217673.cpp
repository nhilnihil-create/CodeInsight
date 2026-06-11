#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

const int M = 200009;
int m;
int d[M], c[M];

pair<int, int> digs(int num) {
    if(num < 10) return {num, 0};
    int ret = 0;
    while(num) {
        ret += num%10;
        num /= 10;
    }
    pair<int, int> rec = digs(ret);
    return {rec.first, 1 + rec.second};
}

pair<int, int> red(int dig, int ct) {
    if(ct == 0) return {0, 0};
    if(ct%2) {
        pair<int, int> tmp = red(dig, ct-1);
        pair<int, int> nxt = digs(tmp.first + dig);
        return {nxt.first, tmp.second + nxt.second + 1};
    } else {
        pair<int, int> tmp = red(dig, ct/2);
        pair<int, int> nxt = digs(tmp.first*2);
        return {nxt.first, tmp.second*2 + nxt.second};
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;
    for(int i = 0; i < m; ++i) cin >> d[i] >> c[i];

    int ans = 0, cur = 0;
    for(int i = 0; i < m; ++i) {
        pair<int, int> x = red(d[i], c[i]);
        ans += x.second;
        cur += x.first;
        pair<int, int> tmp = digs(cur);
        ans += tmp.second;
        cur = tmp.first;
    }

    cout << ans-1 << endl;
    
    return 0;
}
