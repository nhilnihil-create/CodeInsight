#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int A[N];
    double sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    double judge = sum / (4 * M);
    int countItem = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] >= judge) countItem++;
    }
    if (countItem >= M) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}