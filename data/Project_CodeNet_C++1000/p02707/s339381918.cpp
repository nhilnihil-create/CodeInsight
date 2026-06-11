#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A;
    int arrA[N] = {0};
    for (int i = 0; i < N - 1; i++) {
        cin >> A;
        arrA[A - 1]++;
    }

    for (int i = 0; i < N; i++) cout << arrA[i] << endl;
    return 0;
}