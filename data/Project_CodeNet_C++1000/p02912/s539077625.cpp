#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
typedef long long int ll;
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
 
    multiset<int, greater<int>> a;
    int a_;
    rep(i, n) {
        cin >> a_;
        a.insert(a_);
    }

    while (0 < m) {
        auto it = a.begin();
        a_ = *it / 2;
        a.erase(it);
        a.insert(a_);
        m--;
    }

    ll sum = 0;
    auto it = a.begin();
    rep(i, n) {
        sum += *(it++);
    }

    cout << sum << endl;

    return 0;
}