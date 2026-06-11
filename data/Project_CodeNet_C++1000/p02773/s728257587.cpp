#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <map>
#define _GLIBCXX_DEBUG
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s] += 1;
    }
    int max = 0;
    for (auto p : m)
    {
        if (max < p.second)
        {
            max = p.second;
        }
    }
    for (auto p : m)
    {
        if (p.second == max)
        {
            cout << p.first << endl;
        }
    }
}