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

bool isPalin(string word)
{
    string reverse;
    for (int i = word.length() - 1; i > -1; --i)
    {
        reverse += word[i];
    }
    return word == reverse;
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    bool flag = false;
    if (isPalin(s))
    {
        if (isPalin(s.substr(0, (n - 1) / 2)))

        {
            if (isPalin(s.substr((n + 3) / 2 - 1, (n - 1) / 2)))
            {
                flag = true;
            }
        }
    }
    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {

        cout << "No" << endl;
    }
    return 0;
}
