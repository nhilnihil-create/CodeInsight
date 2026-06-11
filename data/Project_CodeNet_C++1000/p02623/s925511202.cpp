#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long> a;
long n,m,i,s,mx,b,l,r,md,k;
int main() {
    cin >> n >> m >> k;
    a.resize(n);
    cin >> a[0];
    mx = 0;
    if(a[0] <= k) mx = 1;
    for(i = 1; i < n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
        if(a[i] <= k) mx = i+1;
    }
    s = 0;
    for(i = 0; i < m; i++) {
        cin >> b;
        s += b;
        if(s > k) break;
        mx = max(mx,i+1);
        l = 0;
        r = n;
        while(r-l > 1) {
            md = (l + r) >> 1;
            if(a[md] > k-s) r = md;
            else l = md;
        }
        if(a[l]+s <= k) {
            mx = max(mx,i+1+l+1);
        }
    }
    cout << mx;
    return 0;
}