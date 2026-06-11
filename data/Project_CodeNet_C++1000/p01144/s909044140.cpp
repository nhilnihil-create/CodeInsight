#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RALL(x) (x).rbegin(),(x).rend()
#define F first
#define S second

void solve(int n, int m) {
    vector<pair<int,int>> data(n); // (p,d)
    for(auto& i : data) cin >> i.S >> i.F;
    sort(RALL(data));

    int ans = 0;
    for(auto& i : data) {
        if(m - i.S >= 0) {
            m -= i.S;
        } else {
            ans += i.F * (i.S - m);
            m = 0;
        }
    }
    cout << ans << "\n";
}

int main() {
    int n,m;
    while(cin>>n>>m, n) solve(n,m);
    return 0;
}