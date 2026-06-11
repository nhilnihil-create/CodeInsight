#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << max(C - (A - B), 0);
}