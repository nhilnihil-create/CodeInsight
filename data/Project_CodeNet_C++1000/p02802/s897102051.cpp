#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, ac[100000], wa[100000];

int main()
{
    cin >> n >> m;
    for (int in = 0; in < m; in++)
    {
        int x;
        cin >> x;
        x--;
        string s;
        cin >> s;

        if (!ac[x])
        {
            if (s == "WA") wa[x]++;
            else ac[x] = 1;
        }
    }

    int AC = 0, WA = 0;
    for (int i = 0; i < n; i++)
    {
        if (ac[i])
        {
            AC++;
            WA += wa[i];
        }
    }

    cout << AC << " " << WA << endl;
}