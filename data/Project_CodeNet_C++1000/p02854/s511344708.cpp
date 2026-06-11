#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    long long sum = 0;
    long long half_sum;
    long long ans = 0;
    long long left = 0;
    long long A[200000];

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i]; 
    }

    half_sum = (long long)(sum / 2);
    for (int i = 0; i < N; i++) {
        left += A[i]; 
        if (left >= half_sum) {
            ans = min(abs(sum-2*left), abs(sum-2*left+2*A[i]));
            break;
        }
    }
    cout << ans << endl;
}
