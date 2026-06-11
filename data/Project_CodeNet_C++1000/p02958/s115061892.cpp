#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <ctime>
#include <assert.h>
using namespace std;

const unsigned long long MOD = (unsigned long long)(1e9 + 7);

#define FROM_0(i, n) for(int i = 0; i < (n); i++)
#define FROM_S(i, s, e) for(int i = (s); i < (e); i++)
#define ITER_BEGIN_END(iter, vec) for(auto iter = vec.begin(); iter != vec.end(); iter++)

bool isSorted(int * p, int n)
{
    FROM_0(i, n - 1)
    {
        if (p[i] > p[i + 1])
            return false;
    }
    return true;
}

int main()
{
    int n;
    int p[100];
    cin >> n;
    FROM_0(i, n)
        cin >> p[i];
    if (isSorted(p, n))
        cout << "YES" << endl;
    else
    {
        FROM_0(i, n)
        {
            FROM_0(j, n)
            {
                if (i == j)
                    continue;
                std::swap(p[i], p[j]);
                if (isSorted(p, n))
                {
                    cout << "YES" << endl;
                    return 0;
                }
                std::swap(p[i], p[j]);
            }
        }
        cout << "NO" << endl;
    }

    return 0;
}
