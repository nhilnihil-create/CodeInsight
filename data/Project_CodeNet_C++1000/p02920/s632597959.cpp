#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    int n = 1 << k, t;
    multiset<int> todo;
    for (int ctr1 = 0; ctr1 < n; ++ctr1)
        cin >> t, todo.insert(-t);
    
    vector<int> done;
    for (int ctr1 = 0; ctr1 <= k; ++ctr1) {
        if (ctr1 == 0) {
            auto it = todo.begin();
            done.push_back(*it);
            todo.erase(it);
        } else {
            int l = 1 << (ctr1 - 1);
            for (int ctr2 = 0; ctr2 < l; ++ctr2) {
                auto it = todo.upper_bound(done[ctr2]);
                if (it == todo.end()) {
                    cout << "No";
                    return 0;
                }
                done.push_back(*it);
                todo.erase(it);
            }
        }
    }

    cout << "Yes";
    return 0;
}