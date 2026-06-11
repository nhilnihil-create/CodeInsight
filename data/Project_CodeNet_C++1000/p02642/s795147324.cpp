#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

//整数xの約数を列挙
void func(int x, vector<int> &fac) {
    while (fac.size())
        fac.pop_back();
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (i != x / i) {
                fac.push_back(i);
                fac.push_back(x / i);
            }
            else
                fac.push_back(i);
        }
    }
}

int main() {
    int n;  cin >> n;
    int *a = new int[n];
    map<int,int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    sort(a, a+n);

    int tmp = 0;
    vector<int> fac;
    for (int i = 0; i < n; i++) {
        if (m[a[i]] > 1) {
            tmp++;
            continue;
        }

        func(a[i], fac);
        for (int j = 0; j < fac.size(); j++) {
            int *k = lower_bound(a, a+n, fac[j]);
            if (*k == fac[j] && fac[j] != a[i]) {
                tmp++;
                break;
            }
        }
    }

    cout << n - tmp << endl;

    return 0;
}