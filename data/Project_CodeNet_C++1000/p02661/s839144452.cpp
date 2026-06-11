#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, n) for (int i = 0; i < (n); ++i)

using ll = long long;
using P = pair<int, int>;


int main() {
    int n;
    cin >> n;

    int m_min;
    int m_max;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n % 2 == 0) {
        m_min = a[n/2 - 1] + a[n/2];
        m_max = b[n/2 - 1] + b[n/2];
        cout << m_max - m_min + 1 << endl;
    } else {
        m_min = a[(n + 1) / 2 - 1];
        m_max = b[(n + 1) / 2 - 1];
        cout << m_max - m_min + 1 << endl;
    }
    return 0;
}