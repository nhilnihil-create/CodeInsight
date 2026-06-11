#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int k, n;
    cin >> k >> n;

    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    v.push_back(v[0] + k);
    
    int j = 0;
    for(int i = 0; i < n; ++i)
    {
        j = max(j, v[i + 1] - v[i]);
    }

    cout << k - j << "\n";
    return 0;
}