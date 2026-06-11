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
    string s;
    cin >> N >> s;
    int L = s.length();
    lli cnt = 0;
    lli r = count(s.begin(), s.end(), 'R');
    lli g = count(s.begin(), s.end(), 'G');
    lli b = count(s.begin(), s.end(), 'B');
    cnt = r * g * b;
    lli cnt2 = 0;
    int k = 0;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            k = 2 * j - i;
            if (k >= 0 && k < N)
            {
                if (s[i] != s[j] && s[j] != s[k] && s[i] != s[k])
                {
                    cnt -= 1;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
