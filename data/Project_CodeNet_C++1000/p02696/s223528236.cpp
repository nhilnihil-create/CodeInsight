#include <bits/stdc++.h>
using namespace std;

long A, B, N;

int main(void) {

    cin >> A >> B >> N;

    long x = N < B-1 ? N : B-1;
    cout << floor(A * x / B) - A * floor(x / B) << endl;

    return 0;

}