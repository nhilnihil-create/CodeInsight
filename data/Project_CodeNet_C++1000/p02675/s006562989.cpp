#include <bits/stdc++.h>
using namespace std;

void solve(long long N)
{
    int n = N % 10;
    if (n == 3)
        cout << "bon" << endl;
    else if (n == 0 || n == 1 || n == 6 || n == 8)
        cout << "pon" << endl;
    else
        cout << "hon" << endl;
}

int main()
{
    long long N;
    scanf("%lld", &N);
    solve(N);
    return 0;
}
