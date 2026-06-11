// https://atcoder.jp/contests/abc175/tasks/abc175_c
#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>
#include <iterator> // std::back_inserter
#include <climits>
#include <sstream>

using namespace std;

typedef unsigned long ll;

ll k;
ll a[1000001];

int main()
{
    cin >> k;
    ll x = 7;
    for (int i=0; i<k; i++) {
        if (x % k == 0) {
            cout << i+1 << endl;
            return 0;
        }
        x = (x * 10 + 7) % k;
    }
    cout << -1 << endl;
}
