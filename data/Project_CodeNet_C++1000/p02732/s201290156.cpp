#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>

using namespace std;

long long int combination2(long long int c);

int main() {
    long long int N, sum = 0;
    cin >> N;

    vector<long long int>A(N), B(N + 1), C(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B[i] = 0;
        C[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        B[A[i]] ++;
    }


    for (int i = 0; i <= N; i++) {
        sum += combination2(B[i]);
    }

    for (int i = 0; i < N; i++) {
        if (C[A[i]] == 0) {
            C[A[i]] = sum - B[A[i]] + 1;
            cout << C[A[i]] << "\n";
        }
        else {
            cout << C[A[i]] << "\n";
        }
    }

    return 0;
}


long long int combination2(long long int c) {
    long long int ans;
    ans = c * (c - 1) / 2;
    return ans;
}

