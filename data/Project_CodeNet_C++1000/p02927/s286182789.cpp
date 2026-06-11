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
    int m, d; cin >> m >> d;
    int ans = 0;
    Rep(i, 4, m) Rep(j, 22, d) {
        if(j/10 >= 2 && j%10 >= 2 && i == (j/10)*(j%10)) ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
