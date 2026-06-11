#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, k, min = 0;
    cin >> n >> k;

    vector<int> p;

    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        p.push_back(x);
    }

    sort(p.begin(), p.end());

    for (size_t i = 0; i < k; i++)
    {
        min += p[i];
    }
    
    cout << min;

    return 0;
}