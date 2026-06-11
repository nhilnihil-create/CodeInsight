#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int h1, h2, m1, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int time1 = h1*60 + m1;
    int time2 = h2*60 + m2;
    time2-=k;
    int ans = time2-time1;
    cout << ans << endl;
    return 0;
}