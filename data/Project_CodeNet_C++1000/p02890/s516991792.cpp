#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(int)(n);i++)

int n,a;
vector<int> c, rui;

int f(int x){
    auto it = lower_bound(c.begin(), c.end(), x);
    int i = (int)(it - c.begin());
    return (n-i) + rui[i] / x;
}

signed main(){
    cin >> n;
    c.resize(n);
    REP(i,n){
        cin >> a;
        c[a-1]++;
    }
    sort(c.begin(), c.end());
    rui.resize(n+1);
    REP(i,n) rui[i+1] = rui[i] + c[i];

    int ans = n;
    REP(i,n){
        while(ans && f(ans) < i+1) ans--;
        cout << ans << "\n";
    }
}