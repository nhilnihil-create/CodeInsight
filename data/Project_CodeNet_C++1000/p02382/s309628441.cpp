#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n;
    cin >> n;
    double x[100], y[100];
    rep(i, 2) {
        rep(j, n) {
            if (i) cin >> y[j];
            else cin >> x[j];
        }
    }
    double ans1=0, ans2=0, ans3=0, ans4=0,tmp;
    rep(i, n) {
        ans1 += abs(x[i] - y[i]);
    }
    rep(i, n) {
        tmp = abs(x[i] - y[i]);
        ans2 += tmp*tmp;
    }
    ans2 = sqrt(ans2);
    rep(i, n) {
        tmp = abs(x[i] - y[i]);
        ans3 += tmp*tmp*tmp;
    }
    ans3 = pow(ans3, 1.0/3.0);
    rep(i, n){
        ans4 = max(ans4, abs(x[i] - y[i]));
    }

    cout << fixed << setprecision(10) << ans1 << endl;
    cout << fixed << setprecision(10) << ans2 << endl;
    cout << fixed << setprecision(10) << ans3 << endl;
    cout << fixed << setprecision(10) << ans4 << endl;

    return 0;
}
