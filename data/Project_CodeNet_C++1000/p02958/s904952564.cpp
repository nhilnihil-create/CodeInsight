#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, mod = 1e9 + 7;

bool check(int a[], int n)
{
    for (int i = 1; i < n; i++)
        if (a[i] <= a[i - 1])
            return false;
    return true;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    int a[52];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(a[i], a[j]);
            if (check(a, n))
                return cout << "YES", 0;
            swap(a[i], a[j]);
        }
    }
    cout << "NO";
    return 0;
}