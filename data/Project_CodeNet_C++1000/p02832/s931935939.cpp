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
    vector<int> a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    b = a;
    sort(b.begin(), b.end());
    if (b[0] != 1)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        int now = 1;
        int cnt = 0;
        int idx = 0;
        for (int i = 0; i < N; i++)
        {
            if (a[i] == 1)
            {
                idx = i;
                break;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (a[i] == now + 1 && i > idx)
            {
                now = a[i];
                idx = i;
            }
            else
            {
                if (a[i] == now && idx == i)
                {
                }
                else
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
