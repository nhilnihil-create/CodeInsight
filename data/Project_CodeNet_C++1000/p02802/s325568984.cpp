#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <iomanip>
#include <numeric>
#include <climits>
#include <algorithm>
#include <cstdint>
using namespace std;

int AWA[100001];
bool AC[100001];

int main()
{
    int n, m;
    cin >> n >> m;

    int cnt_AC = 0;
    int real_WA = 0;

    for (int i = 0; i < m; i++)
    {
        int p;
        string str;
        cin >> p >> str;

        if (!AC[p])
        {
            if (str == "WA")
                AWA[p]++;
            else if (str == "AC")
            {
                AC[p] = true;
                cnt_AC++;
                real_WA += AWA[p];
            }
        }
    }

    cout << cnt_AC << " " << real_WA;
}