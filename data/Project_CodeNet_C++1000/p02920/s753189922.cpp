#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, nn, nr;
    cin >> nn;
    n = (1 << nn);

    multiset <int, greater<int> > slimes, added;
    for (int i = 0; i < n; i++) {
        cin >> nr;
        slimes.insert(nr);
    }

    added.insert(*slimes.begin());

    for (int generation = 0; generation < nn; generation ++) {
        vector <int> children;
        for (auto &&slm :added) {
            if (slimes.upper_bound(slm) == slimes.end()) {
                cout << "No\n";
                return 0;
            }
            children.push_back(*(slimes.upper_bound(slm)));
            slimes.erase(slimes.upper_bound(slm));
        }

        for (auto &&newSlime: children) {
            added.insert(newSlime);
        }
    }

    cout << "Yes\n";
    return 0;
}