#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    sort(v.begin(),v.end());
    double ans = v[0];
    for (int i = 1;i < n;i++) ans = (ans+v[i])/2;
    printf("%lf\n",ans);
}