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
    string s;
    cin >> s;
    int count = 0;

    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s.at(i) != s.at(s.size() - 1 - i))
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}