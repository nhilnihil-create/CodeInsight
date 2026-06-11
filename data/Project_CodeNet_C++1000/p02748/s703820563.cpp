#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, m;
    cin >> a >> b >> m;

    vector<int> fridge(a), microwave(b);
    int minf = 1e6, minm = 1e6;
    for(int i=0; i<a; i++){ cin >> fridge[i]; minf = min(minf, fridge[i]); }
    for(int i=0; i<b; i++){ cin >> microwave[i];  minm = min(minm, microwave[i]); }

    int ans = minf + minm;
    for(int i=0; i<m; i++){
        int x, y, c;
        cin >> x >> y >> c;
        x -= 1;
        y -= 1;
        ans = min(ans, fridge[x] + microwave[y] - c);
    }
    cout << ans << endl;
    return 0;
}