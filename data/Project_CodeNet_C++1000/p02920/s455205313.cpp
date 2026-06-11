#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

int main() {
    int n;
    cin >> n;
    vector<int> s(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        cin >> s[i];
    }
    sort(all(s));  reverse(all(s));

    vector<int> t(1 << n, -1);
    /*
    int i = 0;
    u.push_back(n);
    while (u.size() != i) {
        for (int j = 0; j < u[i]; j++) {
            u.push_back(u[i] - j - 1);
        }
        i++;
    }
    int l = 0, k = 1;
    for (int i = 0; i < n; i++) {
        sort(u.begin() + l, u.begin() + l + k);
        reverse(u.begin() + l, u.begin() + l + k);
        l += k;
        k = k * (n - i) / (i + 1);
    }*/
    /*for (auto i : u) cout << i << " ";
    cout << endl;*/

    priority_queue<int> pq;
    pq.push(n);

    int idx = 0, cap = 1;
    while (idx < (1 << n)) {
        ll sub = 0, sum = 0;
        vector<int> nxt;
        while (s[idx] == s[idx + sub]) {
            if (pq.empty()) {
                cout << "No" << endl;
                return 0;
            }
            sum += pq.top();
            nxt.push_back(pq.top());
            pq.pop();
            sub++;
        }
        for (auto i : nxt) {
            for (int j = 0; j < i; j++) {
                pq.push(j);
            }
        }
        idx += sub;
    }
    cout << "Yes" << endl;
}
