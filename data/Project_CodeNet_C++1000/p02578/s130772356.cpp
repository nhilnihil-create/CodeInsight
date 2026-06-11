#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int64_t ans = 0;
    int MaxNum = 0;
    for (int i = 0; i < N; i++) {
        MaxNum = max(MaxNum, A[i]);
        int Bi = MaxNum;
        ans += Bi - A[i];
    }
    cout << ans << endl;
    return 0;
}
