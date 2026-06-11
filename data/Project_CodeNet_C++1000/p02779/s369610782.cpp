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
    map<int, int> A;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A[a] += 1;
    }
    for (auto p : A)
    {
        if (p.second == 1)
        {
            continue;
        }
        if (p.second != 1)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}