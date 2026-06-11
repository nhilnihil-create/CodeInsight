#include<bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265358979323846;  /* pi */

int main() {
    long long n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    double m1, m2;
    long ans = 0;
    if (n & 1)
    {
        m1 = a[n/2];
        m2 = b[n/2];
        ans = m2 - m1 + 1;
    }
    else
    {
        m1 = (a[(n-1)/2] + (double)a[n/2])/2.0;
        m2 = (b[(n-1)/2] + (double)b[n/2])/2.0;
        double dif = (m2 - m1);
        ans = dif * 2 + 1;
    }
    cout << ans;
    return 0;
}