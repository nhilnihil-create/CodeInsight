#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++)
    {
        if (b[n - 1] != a[i])
        {
            cout << b[n - 1] << endl;
        }
        else
        {
            cout << b[n - 2] << endl;
        }
    }
}