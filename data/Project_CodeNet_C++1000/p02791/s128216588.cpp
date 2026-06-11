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
    vector<int> a;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    int cnt = 0;
    int now = a[0];
    for (int i = 0; i < N; i++)
    {
        now = min(now, a[i]);
        if (now == a[i])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
