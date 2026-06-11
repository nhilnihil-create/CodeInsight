#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, tmp;
    cin >> n;
    vector<int> a(n + 1);

    for(int i = 1; i <= n; ++i)
    {
        cin >> tmp;
        a[tmp] = i;
    }

    for(int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}