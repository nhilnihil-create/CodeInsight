#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <numeric>
#include <map>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

int main()
{
    int l,r,d;
    cin >> l >> r >> d;
    int cnt = 0;
    for (int i = l; i <= r; i++)
    {
        if (i%d == 0)
        {
            cnt++;
        }
        
    }
    cout << cnt << endl;
}