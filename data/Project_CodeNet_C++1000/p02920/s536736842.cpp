#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    auto f = [](const int &a, const int &b) { return a > b; };
    multiset<int, decltype(f)> s(f);
    for(int i = 0, temp = 0; i < 1 << N; i++) cin >> temp, s.insert(temp);

    bool ok = true;
    vector<int> v(1 << N, 0);
    v[0] = *s.begin();
    s.erase(s.begin());
    for(int i = 0; i < N && ok; i++) {
        for(int j = 0, q = 1 << i; j < 1 << i; j++, q++) {
            auto it = s.upper_bound(v[j]);
            if(it != s.end()) {
                v[q] = *it;
                s.erase(it);
            }
            else {
                ok = false;
                break;
            }
        }
    }

    cout << (ok ? "Yes" : "No") << endl; 
    return 0;
}