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
    llong n;
    llong d_sum = 0;
    llong d = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        llong a, b;

        cin >> a >> b;
        d_sum += a * b;
        d += b;
    }

    cout << d + ((d_sum - 1) / 9) - 1 << endl;

    return 0;
}
