#include <iostream>
#include <vector>
using namespace std;

using pint = pair<int,int>;
int main() {
    int N, K; cin >> N >> K;
    int ma = (N-1)*(N-2) / 2;
    if (ma < K) cout << -1 << endl;
    else {
        vector<pint> res;
        for (int i = 1; i <= N-1; ++i) res.push_back({i, N});
        
        int rem = ma - K;
        int ci = 1, cj = 2;
        for (int _ = 0; _ < rem; ++_) {
            res.push_back({ci, cj});
            
            ++cj;
            if (cj == N) {
                ++ci;
                cj = ci + 1;
            }
        }
        
        cout << res.size() << endl;
        for (auto p : res) cout << p.first << " " << p.second << endl;
    }
}