#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const ll INF = 1e18 + 10;
 
int main() {
    int d, t, s;
    cin >> d >> t >> s;
    cout << (s*t >= d ? "Yes" : "No") <<endl;
    return 0;
}