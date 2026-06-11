#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

int main() {
    int N;
    cin >> N;
    multiset<int> s;
    REP(_, 1 << N) {
        int S;
        cin >> S;
        s.insert(-S);
    }

    vector<int> a;

    auto it = s.begin();
    a.push_back(*it);
    s.erase(it);

    REP(k, N) {
        REP(i, 1 << k) {
            auto it = s.upper_bound(a[i]);
            if (it == s.end()) {
                cout << "No" << endl;
                return 0;
            } else {
                a.push_back(*it);
                s.erase(it);
            }
        }
        sort(all(a));
    }
    cout << "Yes" << endl;

    return 0;
}