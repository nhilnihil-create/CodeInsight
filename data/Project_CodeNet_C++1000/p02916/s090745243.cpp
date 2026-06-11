#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> A(n), B(n), C(n - 1);
    for (auto & a : A) {
        cin >> a;
    }
    for (auto & b : B) {
        cin >> b;
    }
    for (auto & c : C) {
        cin >> c;
    }
	int res = 0;
	for (int i = 0; i <= B.size() - 1; i++) {
		res += B[i];
	}
	for(int j = 0; j < n-1; j ++){
		if (A[j] + 1 == A[j + 1]) {
			res += C[A[j] - 1];
		}
	}
    cout << res << endl;
}