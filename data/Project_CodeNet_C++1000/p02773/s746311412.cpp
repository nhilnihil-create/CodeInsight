#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using p = pair<string, int>;

int main()
{
    int n, max_cnt = 0;
    cin >> n;
    
    map<string, int> m;
    set<string> set;

    string tmp;
    for(int i = 0; i < n; ++i)
    {
        cin >> tmp;
        m[tmp]++;
        max_cnt = max(m[tmp], max_cnt);
    }

    for(auto &i: m)
    {
        if(i.second == max_cnt)
            cout << i.first << "\n";
    }
    
    return 0;
}