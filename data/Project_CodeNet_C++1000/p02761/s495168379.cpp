#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    string str = "";

    cin >> n >> m;

    vector<int> s(m), c(m);
    for(int i = 0; i < m; ++i)
    {
        cin >> s[i] >> c[i];
    }

    for(int i = 0; i < 1000; ++i)
    {
        str = to_string(i);

        if(n != str.size())
            continue;

        bool check = true;
        for(int j = 0; j < m; ++j)
        {
            if(int (str[s[j] - 1]) - 48 != c[j])
            {
                check = false;
            }
        }
        if(check) 
        {
            cout << i << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";

    return 0;
}