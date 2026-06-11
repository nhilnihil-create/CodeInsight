#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define ii pair<int, int>

using namespace std;
int n, k;

main() {
//    freopen("in.txt", "r", stdin);
    IOS;
    cin >> n >> k;
    if(k > (n-2)*(n-1)/2) {
        cout << -1;
        exit(0);
    }
    vector<ii> E;
    int r = (n-2)*(n-1)/2 - k;
    for(int i=2; i<=n; i++) E.push_back({1, i});
    for(int i=2; r>0 && i<=n; i++) {
        for(int j=i+1; r>0 && j<=n; j++) {
            E.push_back({i, j});
            r--;
        }
    }
    cout << E.size() << "\n";
    for(ii p : E)   cout << p.first << " " << p.second << "\n";
}
