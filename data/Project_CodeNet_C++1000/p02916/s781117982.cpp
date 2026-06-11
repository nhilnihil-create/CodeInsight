#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

int main() {
    int n; cin >> n;
    vi A(n), B(n), C(n - 1);
    for (auto &a : A) {
        cin >> a;
    }
    for (auto &b : B) {
        cin >> b;
    }
    for (auto &c : C) {
        cin >> c;
    }
    int res = 0, prev = -1;
    for (auto num : A) {
        int idx = num - 1;
        res += B[idx];
        if (idx > 0 && idx == prev + 1) {
            res += C[idx - 1];
        }
        
        prev = idx;
    }
    
    cout << res << endl;
}