#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    int P, Q, R;
    cin >> P >> Q >> R;
    cout << min(P + Q, min(Q + R, R + P));
}