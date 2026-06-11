#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, tmp;
    vector<vector<int>> a(3, vector<int> (3));

    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            cin >> a[i][j];

    cin >> n;
    
    for(int k = 0; k < n; ++k)
    {
        cin >> tmp;
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
            {
                if(a[i][j] == tmp)
                    a[i][j] = 0;
            }
    }

    bool bingo = false;
    for(int i = 0; i < 3; ++i)
    {
        if(!a[i][0] && !a[i][1] && !a[i][2])
            bingo = true;
    }
    for(int j = 0; j < 3; ++j)
    {
        if(!a[0][j] && !a[1][j] && !a[2][j])
            bingo = true;
    }

    if(!a[0][0] && !a[1][1] && !a[2][2])
        bingo = true;
    if(!a[0][2] && !a[1][1] && !a[2][0])
        bingo = true;

    cout << (bingo ? "Yes" : "No") << "\n";
    return 0;
}