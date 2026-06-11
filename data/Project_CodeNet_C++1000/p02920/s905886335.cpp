#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    multiset<int> notdone, done;
    for (int i = 0; i < (1 << n); i++) {
        int a;
        cin >> a;
        notdone.insert(-a);
    }
    done.insert(*notdone.begin());
    notdone.erase(notdone.begin());
    for (int i = 0; i < n; i++) {
        multiset<int> temp;
        for (auto x: done) {
            set<int>::iterator it = notdone.upper_bound(x);
            if (it == notdone.end()) continue;
            temp.insert(*it);
            notdone.erase(it);
        }
        for (auto x: temp)
            done.insert(x);
    }
    if (done.size() == (1 << n)) cout << "Yes";
    else cout << "No";
    return 0;
}
