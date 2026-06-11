#include <bits/stdc++.h>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define NMAX 100013
using namespace std;
int N, M, R, C, x, y, start, j;
multiset <int> target;
multiset <int> curr;
int main() {
    cin >> N;
    int M  = (1 << N);
    vector <int> A(M);
    for (int i = 0; i < M; ++i)
        cin >> x, target.insert(-1 * x);
    curr.insert(*(target.begin()));
    target.erase(target.begin());
    while (!target.empty()) {
        multiset <int> toadd;
        for (auto x : curr) {
            auto pos = target.upper_bound(x);
            if (pos == target.end()) {
                cout << "No\n";
                return 0;
            }
            toadd.insert(*pos);
            target.erase(pos);
        }
        for (auto x : toadd)
            curr.insert(x);
    }
    cout << "Yes\n";
    return 0;
}
