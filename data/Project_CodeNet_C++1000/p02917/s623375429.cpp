#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> B(N-1);
    for (int i = 0; i < N-1; ++i) cin >> B[i];

    long long res = B[0] + B.back();
    for (int i = 0; i + 1 < B.size(); ++i) {
        res += min(B[i], B[i+1]);
    }
    cout << res << endl;
}