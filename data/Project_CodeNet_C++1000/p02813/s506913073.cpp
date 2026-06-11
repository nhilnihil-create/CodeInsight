#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;


int main() {
    int n;  cin >> n;
    vector<ll> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        q[i]--;
    }
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i;
    
    int a, b, cnt = 1;;
    do {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (p[i] != v[i])
                flag = false;
        }
        if (flag)
                a = cnt;

        flag = true;
        for (int i = 0; i < n; i++) {
            if (q[i] != v[i])
                flag = false;
        }
        if (flag)
            b = cnt;
        cnt++;
    } while (next_permutation(v.begin(), v.end()));

    cout << abs(a-b) << endl;

    return 0;
}