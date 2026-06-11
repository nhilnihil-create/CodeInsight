#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    long long n, k;
    cin >> n >> k;

    long long q = n % k;

    cout << min(q, abs(k - q)) << endl;
}
