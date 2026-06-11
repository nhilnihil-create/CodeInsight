#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <iomanip>
#include <numeric>
#include <climits>
#include <algorithm>
#include <cstdint>
using namespace std;

int main()
{
    int n, k;
    long long r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;

    long long pts = 0;
    for (int i = 0; i < k; i++)
    {
        if (t[i] == 'r')
        {
            pts += p;
            t[i] = 'p';
        }
        else if (t[i] == 'p')
        {
            pts += s;
            t[i] = 's';
        }
        else
        {
            pts += r;
            t[i] = 'r';
        }
    }

    for (int i = k; i < n; i++)
    {
        if (t[i] == 'r' && t[i - k] != 'p')
        {
            pts += p;
            t[i] = 'p';
        }
        else if (t[i] == 'p' && t[i - k] != 's')
        {
            pts += s;
            t[i] = 's';
        }
        else if (t[i] == 's' && t[i - k] != 'r')
        {
            pts += r;
            t[i] = 'r';
        }
        else t[i] = '?';
    }

    cout << pts;
}