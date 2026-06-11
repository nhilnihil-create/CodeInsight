#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    int dmax = 100000;
    vector<int> cnt(dmax+1);
    rep(i,n){
        cin >> d[i];
        cnt[d[i]]++;
    }
    rep(i,dmax) cnt[i+1]+=cnt[i];
    if(n%2){
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    rep(i,dmax+1) if(cnt[i]==n/2) ans++;
    cout << ans << endl;
}