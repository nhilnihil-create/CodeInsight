#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;

const unsigned long long BASE = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int * a = new int[n];
    int * b = new int[n];
    int * c = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n - 1; i++)
        cin >> c[i];

    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += b[a[i] - 1];
        if (i > 0 && a[i] == a[i - 1] + 1)
        {
            ret += c[a[i - 1] - 1];
        }
    }
    cout << ret;

    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}
