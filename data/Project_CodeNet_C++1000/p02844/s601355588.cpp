#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    // change to number
    int * pN = new int[n];
    for (int i = 0; i < n; i++)
    {
        pN[i] = (s[i] - '0');
    }
    // make before and after array
    int * pBefore = new int[n];
    int * pAfter = new int[n];
    pBefore[0] = 0;
    for (int i = 1; i < n; i++)
    {
        pBefore[i] = pBefore[i - 1] | (1 << pN[i - 1]);
    }
    pAfter[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        pAfter[i] = pAfter[i + 1] | (1 << pN[i + 1]);
    }
    // calculate
    bool has[1000];
    for (int i = 0; i < 1000; i++)
        has[i] = false;
    for (int i = 1; i < n - 1; i++)
    {
        int now = pN[i] * 10;
        for (int before = 0; before < 10; before++)
        {
            if ((pBefore[i] & (1 << before)) == 0)
                continue;
            for (int after = 0; after < 10; after++)
            {
                if ((pAfter[i] & (1 << after)) == 0)
                    continue;
                has[before * 100 + now + after] = true;
            }
        }
    }
    // count
    int count = 0;
    for (int i = 0; i < 1000; i++)
        count += has[i];
    cout << count << endl;

    delete[] pN;
    delete[] pBefore;
    delete[] pAfter;
    return 0;
}
