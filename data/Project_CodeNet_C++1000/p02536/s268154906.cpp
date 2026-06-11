// ACLBC-C.cpp

#include <iostream>
#include <atcoder/dsu> // 無向グラフ DSU  Union-Find
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n,m;
    cin >> n>>m;
    dsu d(n); // Union-Find
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        d.merge(a, b); // 点を追加する
    }
    int cnt = 0;
    //rep(i, n) if (d.leader(i) == i) cnt++;
    cnt = d.groups().size();
    int ans = cnt - 1;
    cout << ans << endl;
}
