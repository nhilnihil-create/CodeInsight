#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, K, Q; cin >> N >> K >> Q;
    vector<int> A(N, K);
    for (int i = 0; i < Q; ++i) {
        int a = 0; cin >> a;
        A[a - 1]++;
    }
    for (int i = 0; i < N; ++i) {
        A[i] -= Q;
        if (A[i] <= 0) printf("%s\n", "No");
        else printf("%s\n", "Yes");
    }
}
