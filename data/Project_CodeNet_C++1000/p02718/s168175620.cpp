#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m, t = 0, cnt = 0;
    cin >> n >> m;
    vector<int> v(n);

    for(int i = 0; i < n; ++i) 
    {
            cin >> v[i];
            t += v[i];
    }

    for(int i: v) if(i * 4 * m >= t) cnt++;
    
    cout << (cnt >= m ? "Yes" : "No") << "\n";
    return 0;
}