#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        cin >> s[i];
    }

    multiset<int> tree(s.begin(), s.end());
    auto it = --tree.end();

    vector<int> state = {*it};
    tree.erase(it);

    for(int t = 0; t < n; t++) {
        for (int i = 0; i < (1 << t); i++) {
            int from = state[i];
            auto it = tree.lower_bound(from);
            if (it == tree.begin()) {
                cout << "No" << endl;
                return 0;
            }

            --it;
            state.push_back(*it);
            tree.erase(it);
        }
    }

    cout << "Yes" << endl;
}
