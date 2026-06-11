#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    int n;
    cin >>n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    reverse(all(h));
    int ans = 0;
    int val = 0;
    for (int i = 1; i < n; i++) {
        if (h[i-1] <= h[i]) val++;
        else val = 0;
        ans = max(ans, val);
    }
    cout << ans << endl;

    return 0;
}