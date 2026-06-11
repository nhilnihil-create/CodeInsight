#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <bitset>
using namespace std;
typedef long long int lli;
int main(void)
{
    int N;
    cin >> N;
    vector<int> h;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        h.push_back(tmp);
    }
    int ans = 0;
    int cnt = 0;
    vector<int> cntarray;
    for (int i = 0; i < N - 1; i++)
    {
        if (h[i] >= h[i + 1])
        {
            cnt++;
            ans = max(ans, cnt);
        }
        else
        {
            cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}