#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    long long ans = 0;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        ans -= 1LL * min(u, v) * (n - max(u, v) + 1);
    }
    #ifdef DEBUG
    cout << ans << "\n";
    #endif
    for(int l = 1; l <= n;l ++){
        ans += 1LL * (n - l + 1) * (n - l  + 2) / 2;
    }
    cout << ans;
}