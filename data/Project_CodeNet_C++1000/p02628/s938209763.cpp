#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p.at(i);
    sort(p.begin(),p.end());
    int ans=0;
    rep(i,k) ans += p.at(i);
    cout << ans << endl;
    return 0;
}