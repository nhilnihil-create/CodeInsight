/**
*    author:  Dooloper
*    created: 17.09.2020 18:17:42
**/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <functional>
#include <cassert>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define PI 3.14159265358979323846264338327950L

int main()
{
    cin.tie(0);
    string S, T;
    cin >> S >> T;

    int currentMin = 100000;
    for (int i = 0; i < S.size() - T.size() + 1; i++)
    {
        int cnt = 0;
        for (int j = 0; j < T.size(); j++)
        {
            if(S[i+j] != T[j])
                cnt++;
        }
        currentMin = min(cnt, currentMin);
    }
    cout<<currentMin <<endl;

    return 0;
}
