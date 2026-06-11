#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
int const INF = 1 << 30;


int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int l = 0, r = INF;
    while(r - l > 1) {
        int mid = (l + r)/2;
        auto C = [&]() {
            int cnt = 0;
            rep(i,n) cnt += (a[i]-1)/mid;
            return cnt <= k;
        };
        if(C()) r = mid;
        else l = mid;
    }

    cout << r << endl;
    return 0;
}