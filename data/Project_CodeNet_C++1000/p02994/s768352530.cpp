#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    int sum = 0, minv = 100100;
    for (int i = L; i < L + N; i++) {
        sum += i;
        if (abs(i) < abs(minv)) minv = i;
    }
    cout << sum - minv << endl;
}