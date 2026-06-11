#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <map>
#include <iomanip>
#include <stdio.h>
#include <bitset>

typedef long long ll;

constexpr long long INFLL = 1e18;

using namespace std;

int main()
{
    int n;
    cin >> n;
    //vector<vector<int>> x(n, vector<int>(15));
    vector<vector<int>> x(n, vector<int>(0));
    vector<vector<int>> y(n, vector<int>(0));
    vector<int> a(n);

    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
        for (int l = 0; l < a.at(i); l++)
        {
            //cin >> x.at(i).at(l);
            cin >> temp;
            x.at(i).push_back(temp);
            cin >> temp;
            y.at(i).push_back(temp);
        }
    }

    vector<int> tr_fa(n);
    bool ch;
    int ans = 0;
    int sum;

    for (int i = 0; i < (1 << n); i++)
    {
        sum = 0;
        for (int l = 0; l < n; l++)
        {
            if (i & (1 << l))
            {
                tr_fa.at(l) = 1;
                sum++;
            }
            else
            {
                tr_fa.at(l) = 0;
            }
        }

        ch = true;

        for (int l = 0; l < n; l++)
        {
            if (ch == false)
            {
                break;
            }
            if (tr_fa.at(l))
            {
                for (int m = 0; m < x.at(l).size(); m++)
                {
                    if (tr_fa.at(x.at(l).at(m) - 1) != y.at(l).at(m))
                    {
                        // cout << "l:" << l << " m:" << m << endl;
                        ch = false;
                        break;
                    }
                }
            }
            /*
            else
            {
                for (int m = 0; m < x.at(l).size(); m++)
                {
                    if (tr_fa.at(x.at(l).at(m) - 1) == y.at(l).at(m))
                    {
                        cout << "l:" << l << " m:" << m << endl;
                        ch = false;
                        break;
                    }
                }
            }
            */
        }

        if (ch)
        {
            if (ans < sum)
            {
                ans = sum;
            }
        }
    }

    cout << ans << endl;

    return 0;
}