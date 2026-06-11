#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

#define N 1000000007

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a);
    vector<ll> q(b);
    vector<ll> r(c);
    for (int i = 0; i < a; i++)
        cin >> p[i];
    for (int i = 0; i < b; i++)
        cin >> q[i];
    for (int i = 0; i < c; i++)
        cin >> r[i];

    sort(p.begin(), p.end(), [](ll x, ll y){ return x > y; });
    sort(q.begin(), q.end(), [](ll x, ll y){ return x > y; });
    sort(r.begin(), r.end(), [](ll x, ll y){ return x > y; });

    int a_i = x - 1, b_i = y - 1, c_i = 0;

    while (a_i >= -1 && b_i >= -1 && c_i < c) {
        if (a_i >= 0 && b_i >= 0 && p[a_i] < r[c_i] && q[b_i] < r[c_i]) {
            if (p[a_i] < q[b_i]) {
                a_i--;
            } else {
                b_i--;
            }
            c_i++;
        } else if (a_i >= 0 && p[a_i] < r[c_i]) {
            a_i--;
            c_i++;
        } else if (b_i >= 0 && q[b_i] < r[c_i]) {
            b_i--;
            c_i++;
        } else {
            break;
        }
    }

    ll sum = 0;
    for (int i = 0; i <= a_i; i++)
        sum += p[i];
    for (int i = 0; i <= b_i; i++)
        sum += q[i];
    for (int i = 0; i < c_i; i++)
        sum += r[i];

    cout << sum << endl;
    return 0;
}