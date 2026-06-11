#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int ans = 0;
    int mini = 1000000;
    for(int i = 0; i < n; i++) {
        mini = min(mini, p[i]);
        if(p[i] <= mini) ans++;
    }

    cout << ans << endl;
}