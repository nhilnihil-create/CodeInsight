#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<long long int> A(N, 0);
    long long int sum = 0, mini = 0, S = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; S += A[i];
    }
    mini = S;
    for (int i = 0; i < N; ++i) {
        sum += A[i];
        mini = min(mini, abs(sum - (S - sum)));
    }
    printf("%d\n", mini);
}
