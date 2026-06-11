#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    multiset<int> mada;
    for (int i = 0; i < 1 << n; i++) {
        int a;
        cin >> a;
        mada.insert(a);
    }

    auto it = mada.end();
    it--;
    vector<int> dekita = {*it};
    mada.erase(it);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1 << i; j++) {
            int a = dekita[j];
            auto it = mada.lower_bound(a);
            if (it == mada.begin()) {
                cout << "No" << endl;
                return 0;
            }
            it--;
            dekita.push_back(*it);
            mada.erase(it);
        }
    }

    cout << "Yes" << endl;
}
