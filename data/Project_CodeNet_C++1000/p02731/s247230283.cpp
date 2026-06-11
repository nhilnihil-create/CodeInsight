#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (2147483647)
#define MOD (int)(1e9 + 7) 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double ans = 0;
    double s;
    cin >> s;
    int res = (s/3);
    double min = res * res * res;
    if((int)s%3 == 0) {
        ans = min;
    }
    else {
        for(int i = 0; i <= 1000; ++i) {
            for(int j = 0; j <= 1000; ++j) {
                double ii = (double)i/(double)1000;
                double jj = (double)j/(double)1000;
                double kk = s - (res+ii) - (res+jj);
                ans = max(ans, (res+ii)*(res+jj)*kk);
            }
        }
    }
    cout << fixed << setprecision(12) << ans << '\n';
    return 0;
}