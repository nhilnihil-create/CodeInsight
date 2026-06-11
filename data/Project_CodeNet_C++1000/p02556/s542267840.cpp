#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        a[i] = x + y;
        b[i] = x - y;
    }

    int o = -INF, p = INF, q = -INF, r = INF;
    for(int i = 0; i < n; ++i){
        o = max(o, a[i]);
        p = min(p, a[i]);
        q = max(q, b[i]);
        r = min(r, b[i]);
    }
    int ans = max(o - p, q - r);
    cout << ans << "\n";

    return 0;
}
