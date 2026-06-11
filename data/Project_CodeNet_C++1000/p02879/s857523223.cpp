#include <bits/stdc++.h>
using namespace std;

void solve(int A, int B)
{
    cout << ((A < 10 && B < 10) ? A * B : -1) << endl;
}

int main()
{
    int A;
    cin >> A;
    int B;
    cin >> B;
    solve(A, B);
    return 0;
}
