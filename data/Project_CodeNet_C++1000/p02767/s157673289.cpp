#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> x(n); rep(i,n) cin >> x[i];
    int ans = 1000000;
    for(int i = 1; i <= 100; i++) {
    int tmp = 0;
        rep(j,n) {
            tmp += (x[j] - i)*(x[j] - i);
        }
        ans = min(ans,tmp);
    }    
    cout << ans << endl;
}