#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0);   cin.tie(0);
    cin >> n;
    v.resize(1 << n);
    for(int i = 0; i < (1 << n); ++i)   cin >> v[i];
    sort(v.begin(), v.end());
    multiset<int> t;    t.insert(v.back());
    v.pop_back();
    multiset<int> s(v.begin(), v.end());

    for(int i = 0; i < n; ++i) {
        vector<int> tmp;
        for(auto j : t) {
            auto it = s.lower_bound(j);
            if(it == s.begin()) {
                cout << "No";
                return 0;
            }
            tmp.push_back(*prev(it));
            s.erase(prev(it));
        }
        for(auto j : tmp)   t.insert(j);
    }
    cout << "Yes";
    return 0;
}