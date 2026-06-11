#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main() {
    lint k, q;
    cin >> k >> q;

    vector<lint> d(k);
    for(auto& elem : d)  cin >> elem;

    while(q--) {
        lint n, x, m;
        cin >> n >> x >> m;

        x %= m;
        vector<lint> dm(d.begin(), d.end());
        for(auto& elem : dm) {
            elem %= m;
            if(elem == 0)  elem = m;
        }

        partial_sum(begin(dm), end(dm), begin(dm));
        dm.insert(begin(dm), 0);

        lint last = x + ((n-1)/k) * dm[k] + dm[(n-1)%k];
        cout << (n-1) - (last / m) << endl;
    }
}