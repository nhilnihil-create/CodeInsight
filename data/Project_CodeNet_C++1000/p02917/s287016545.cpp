#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)

int main() {
    int n;
    cin >> n;
    vector<int> b(n-1);
    rep(i,n-1) cin >> b[i];
    int ans = b[0]+b[n-2];
    rep(i,n-2){
        ans += min(b[i],b[i+1]);
    }
    cout << ans << endl;
}