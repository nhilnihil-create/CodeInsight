#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>           // sorted map so O(logn)
#include <unordered_map> // O(1)
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool flag = true;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        mp[x]++;
        if (mp[x] > 1)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {

        cout << "NO" << endl;
    }

    return 0;
}