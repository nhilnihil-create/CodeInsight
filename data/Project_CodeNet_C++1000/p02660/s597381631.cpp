#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    LL n;
    cin>>n;
    vector<pair<LL, int> > dvs;//配对<质数, 幂次>
    //质因数分解
    for (LL i=2; i*i<=n; i++) {
        if (0==n%i) {
            dvs.push_back(make_pair(i, 0));
            while (0==n%i) {
                dvs.back().second++;
                n /= i;
            }
        }
    }
    if (n>1) {
        dvs.push_back(make_pair(n, 1));
    }
    //遍历
    int ans = 0;
    for (pair<LL, int> &p:dvs) {
        int i=sqrt(p.second*2);
        if (i*(i+1)>p.second*2) {
            i--;
        }
        ans += i;
    }
    cout << ans << endl;
    return 0;
}
