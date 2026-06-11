#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i=0;i<(int)(n);i++)

int n,a;
vector<int> c, rui;

bool f(int x,int k){
    auto it = lower_bound(c.begin(), c.end(), x);
    int i = (int)(it - c.begin()) - 1;
    return (!x) || (n-i) + rui[i] / x >= k;
}

signed main(){
    cin >> n;
    c.resize(n+1);
    REP(i,n){
        cin >> a;
        c[a]++;
    }
    sort(c.begin(), c.end());
    rui.resize(n+1);
    REP(i,n) rui[i+1] = rui[i] + c[i+1];

    int ans = n;
    REP(i,n){
        while(!f(ans, i+1)) ans--;
        cout << ans << endl;
    }
}