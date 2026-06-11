#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> A(N, 0);
    vector<int> B(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; B[i] = A[i];
    }
    sort(B.begin(), B.end(), greater<int>());
    for (int i = 0; i < N; ++i) {
        if (A[i] == B[0]) printf("%d\n", B[1]);
        else printf("%d\n", B[0]);
    }
}
