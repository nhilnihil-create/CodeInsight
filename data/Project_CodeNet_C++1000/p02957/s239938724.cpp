#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    int A, B;
    cin >> A >> B;
    if ((A + B) % 2 == 0)
        cout << (A + B) / 2;
    else
        cout << "IMPOSSIBLE";
}