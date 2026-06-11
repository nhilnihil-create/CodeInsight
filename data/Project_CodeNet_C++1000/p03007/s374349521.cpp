#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main(void) {
    int n, i, a[100003], sum, ksum;
    vector<int> po, ne;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    sum = 0;
    for (i = 0; i < n; i++) {
        if (i == 0) {
            sum += -a[i];
            ne.push_back(a[i]);
        }
        else if (i == n - 1) {
            sum += a[i];
            po.push_back(a[i]);
        }
        else {
            sum += abs(a[i]);
            if (a[i] >= 0) po.push_back(a[i]);
            else ne.push_back(a[i]);
        }
    }

    cout << sum << endl;

    ksum = ne[0];
    for (i = 0; i < po.size() - 1; i++) {
        cout << ksum << ' ' << po[i] << endl;
        ksum -= po[i];
    }

    cout << po[po.size() - 1] << ' ' << ksum << endl;

    ksum = po[po.size() - 1] - ksum;

    for (i = 1; i < ne.size(); i++) {
        cout << ksum << ' ' << ne[i] << endl;
        ksum += -ne[i];
    }

    return 0;
}