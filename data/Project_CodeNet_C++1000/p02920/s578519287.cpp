#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    multiset<int> unused;
    for(int i = 0; i < 1 << n; ++i) {
        int a; cin >> a;
        unused.insert(a);
    }

    multiset<int> used;
    used.insert(*prev(unused.end()));
    unused.erase(prev(unused.end()));
    for(int i = 0; i < n; ++i) {
        multiset<int> nused;
        for(auto a : used) {
            auto it = unused.lower_bound(a);
            if(it == unused.begin()) {
                break;
            }
            it = prev(it);
            nused.insert(a);
            nused.insert(*it);
            unused.erase(it);
        }
        used = move(nused);
    }

    cout << (unused.empty() ? "Yes" : "No") << endl;
}
