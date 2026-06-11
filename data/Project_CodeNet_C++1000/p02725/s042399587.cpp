#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

int main()
{
    int k, n; cin >> k >> n;
    vector<int> a(n); rep(i,n) cin >> a.at(i);
    int ans = k;
    rep(i, n) {
        int p1,p2; //p1 ClockWise, p2 CouterClockWise

        if(i == 0) p1 = a.at(n-1) - a.at(0);
        else p1 = k - (a.at(i) - a.at(i-1));

        if(i == n-1) p2 = k - (a.at(i) - a.at(i-1));
        else p2 = k - (a.at(i+1) - a.at(i));

        int tmp = min(p1,p2);
        ans = min(ans, tmp);

    }
    cout << ans << endl;
}