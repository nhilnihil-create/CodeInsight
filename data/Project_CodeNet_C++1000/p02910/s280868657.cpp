#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>           // sorted map so O(logn)
#include <unordered_map> // O(1)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool flag = false;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != 'U' && s[i] != 'D')
        {

            if ((i + 1) % 2 != 0)
            {
                if (s[i] != 'R')
                {
                    flag = true;
                    break;
                }
            }
            else
            {
                if (s[i] != 'L')
                {
                    flag = true;
                    break;
                }
            }
        }
    }
    if (flag)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}
