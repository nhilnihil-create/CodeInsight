#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; cin >> n;
    int x[102] = {0};
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> x[i]; sum += x[i];
    }
    int c = sum / n;
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++)
    {
        d1 += (c - x[i]) * (c - x[i]);
        d2 += (c + 1 - x[i]) * (c + 1 - x[i]);
    }
    int ans = min(d1, d2);
    cout << ans << endl;
}