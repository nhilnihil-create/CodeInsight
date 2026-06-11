#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

const unsigned long long BASE = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int * b = new int[n];
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
        if (i > 0)
        {
            sum += b[i] > b[i - 1] ? b[i - 1] : b[i];
        }
    }
    sum += b[0] + b[n - 2];
    cout << sum;

    delete[] b;
    return 0;
}
