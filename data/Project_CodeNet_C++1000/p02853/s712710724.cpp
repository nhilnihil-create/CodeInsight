#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

int main() {
    llong ans = 0;
    llong x, y;

    cin >> x >> y;

    if (x == 3) ans += 100000;
    if (x == 2) ans += 200000;
    if (x == 1) ans += 300000;
    if (y == 3) ans += 100000;
    if (y == 2) ans += 200000;
    if (y == 1) ans += 300000;

    if (x == 1 && y == 1) ans += 400000;

    cout << ans << endl;

    return 0;
}
