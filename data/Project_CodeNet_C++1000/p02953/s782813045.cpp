#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <stack>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    int N;
    cin >> N;
    int tmp;
    vector<int> h, cp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        h.push_back(tmp);
    }
    int bigger = 0;
    for (int i = 0; i < N; i++)
    {
        bigger = max(h[i], bigger);
        if (bigger - h[i] >= 2)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
