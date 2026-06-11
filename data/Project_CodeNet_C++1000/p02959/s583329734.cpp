#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int A[N+1], B[N];
    for (int i = 0; i < N+1; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    long long killcount = 0;
    for (int i = 0; i < N; i++) {
        if (B[i] <= A[i]) {
            killcount += B[i];
        }
        else {
            killcount += A[i];
            if (A[i+1] >= B[i]-A[i]) {
                killcount += B[i]-A[i];
                A[i+1] -= B[i]-A[i];
            }
            else {
                killcount += A[i+1];
                A[i+1] = 0;
            }
        }
    }

    cout << killcount << endl;
}
