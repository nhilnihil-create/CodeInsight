#include <iostream>
#include <string>
#include <algorithm>
#define int long long
using namespace std;

signed main() {
    int n;
    int d[100000];
    int l,r,ans;

    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> d[i];
    }
    sort(d,d+n);
    r = n/2;
    l = r-1;
    ans = d[r]-d[l];
    cout << ans;
    return 0;
}