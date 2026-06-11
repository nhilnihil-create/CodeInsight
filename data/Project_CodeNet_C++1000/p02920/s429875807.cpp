#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef multiset<int> si;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    si s;
    for (int i = 0; i < 1 << n; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }

    vi a;
    a.push_back(*s.rbegin());
    s.erase(prev(s.end()));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 1 << i - 1; j++) {
            auto it = s.lower_bound(a[j]);
            if (it == s.begin()) {
                cout << "No" << endl;
                return 0;
            } else {
                a.push_back(*--it);
                s.erase(it);
            }
        }

        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
    }

    cout << "Yes" << endl;

    return 0;
}
