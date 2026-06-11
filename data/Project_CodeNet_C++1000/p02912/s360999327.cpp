#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const int INF = 1000000000;
const double PI = 3.1415926535897932;
const ll MOD = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;

    priority_queue<int> pque;
    rep(i, n) {
        int a;
        cin >> a;
        pque.push(a);
    }
    rep(i, m) {
        int discount = pque.top() / 2;
        pque.pop();
        pque.push(discount);
    }
    ll ans = 0;
    while(!pque.empty()) {
        int price = pque.top();
        pque.pop();
        ans += ll(price);
    }
    cout << ans << endl;
    return 0;
}