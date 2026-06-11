#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[1<<n];
    for (int i = 0; i < 1<<n; i++) cin >> a[i];
    sort(a, a+(1<<n));
    vector<int> A({a[(1<<n)-1]});
    multiset<int> B(a, a+(1<<n)-1);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < 1<<k; i++) {
            auto j = B.lower_bound(A[i]);
            if (j == B.begin()) { cout << "No\n"; return 0; }
            j--;
            A.push_back(*j);
            B.erase(j);
        }
    }
    cout << "Yes\n";
}
