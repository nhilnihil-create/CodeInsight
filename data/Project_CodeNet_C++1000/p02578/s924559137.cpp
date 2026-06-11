#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> A(N), height(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long sum = 0;
    int max_height = 0;
    for (int i = 0; i < N; i++) {
        max_height = max(max_height, A[i]);
        sum += max_height - A[i];
    }

    cout << sum << endl;
    
    return 0;
}