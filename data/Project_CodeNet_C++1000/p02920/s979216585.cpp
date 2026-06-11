#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    multiset<int> s;
    vector<int> v;

    for (int i = 0; i < (1 << n); i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    v.push_back(*s.rbegin());
    s.erase(--s.end());

    while (v.size() < (1 << n)) {
        vector<int> tmp;

        for (int x : v) {
            auto it = s.lower_bound(x);
            if (it == s.begin())
                return cout << "No\n", 0;

            it--;
            tmp.push_back(*it);
            s.erase(it);
        }

        for (int x : tmp)
            v.push_back(x);
    }

    cout << "Yes\n";

    return 0;
}
