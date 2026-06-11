#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <list>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define debug(x) (cout << # x ": " << x << endl)
#define ll long long int
#define repeat(n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()

int main() {
    int n;
    cin >> n;

    vector<int> va, vb;

    repeat(n) {
        int a, b;
        cin >> a >> b;
        va.push_back(a);
        vb.push_back(b);
    }

    sort(all(va));
    sort(all(vb));

    if (n % 2 == 1) {
        cout << vb[n / 2] - va[n / 2] + 1;
    } else {
        cout << vb[n / 2] + vb[n / 2 - 1] - va[n / 2] - va[n / 2 - 1] + 1;
    }

    return 0;
}