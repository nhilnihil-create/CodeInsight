#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    multiset<int> ms, check;
    for (int i = 0; i < (1 << n); ++ i) {
        int a;
        cin >> a;
        ms.insert(a);
        check.insert(a);
    }
    multiset<int> make;
    make.insert(*(-- ms.end()));
    ms.erase(-- ms.end());
    while (make.size() != (1 << n)) {
        vector<int> tmp;
        for (auto it = make.rbegin(); it != make.rend(); ++ it) {
            auto x = ms.lower_bound(*it);
            if (x == ms.begin()) {
                cout << "No";
                return 0;
            }
            x --;
            tmp.emplace_back(*x);
            ms.erase(x);
        }
        for (auto& x : tmp) make.insert(x);
    }
    if (check == make) cout << "Yes";
    else cout << "No";
}