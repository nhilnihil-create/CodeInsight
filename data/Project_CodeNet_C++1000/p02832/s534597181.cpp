#include <bits/stdc++.h>
using namespace std;

// 
int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int num = 1;
    int skipCount = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == num) num++;
        else skipCount++;
    }
    if (num == 1) {
        cout << -1;
        return 0;
    }
    cout << skipCount;
}
