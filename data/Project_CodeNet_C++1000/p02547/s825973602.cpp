#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;

const int MOD = 1e9+7;
const ll INF = 1e16;

int main() {
    FASTIO

    int n;
    cin >> n;
    vector<bool> v(n);
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = (x == y);
    }
    bool flag = false;
    for(int i=0; i<n-2; i++) {
        if(v[i] && v[i+1] && v[i+2]) {
            cout << "Yes\n";
            flag = true;
            break;
        }
    }
    if(!flag) cout << "No\n";
    
    return 0;
}