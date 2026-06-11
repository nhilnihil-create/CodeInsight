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
    double x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double x, y;
    x = (x2 - x1) * (x2 - x1);
    y = (y2 - y1) * (y2 - y1);
    double ans = sqrt(x + y);
    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}
