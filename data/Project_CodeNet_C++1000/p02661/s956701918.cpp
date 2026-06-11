#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
int a[maxn];
int b[maxn];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i] >> b[i];
    }
    sort(begin(a), begin(a) + n);
    sort(begin(b), begin(b) + n);
    if (n & 1)
    {
        ll left = a[n / 2], right = b[n / 2];
        cout << right - left + 1 << endl;
    }
    else
    {
        ll l1 = a[(n - 1) / 2], r1 = b[(n - 1) / 2], l2 = a[n / 2], r2 = b[n / 2];
        cout << (r1 + r2) - (l1 + l2) + 1 << endl;
    }
    return 0;
}