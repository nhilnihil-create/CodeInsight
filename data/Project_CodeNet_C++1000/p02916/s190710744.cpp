#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> A(n), B(n), C(n - 1);
    for (auto &a : A) {
        cin >> a;
    }
    for (auto &b : B) {
        cin >> b;
    }
    for (auto &c : C) {
        cin >> c;
    }
    int res = 0;
    for (int i = 0; i < n-1; i++) {
        res = res + B[i];
        if ((A[i] + 1) == (A[i + 1])) {
            res = res + C[A[i] - 1];
        }
    }
    res = res + B.back();
    cout << res;
    
	return 0;
}
