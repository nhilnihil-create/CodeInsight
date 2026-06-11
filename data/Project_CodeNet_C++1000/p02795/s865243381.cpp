#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

void solve() {
    ll h, w, n;
    cin >> h >> w >> n;
    ll M = max(h, w);
    ll o = M, cnt = 1;
    while(1){
        if(o >= n) break;
        o += M;
        cnt++;
    }
    cout << cnt << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
