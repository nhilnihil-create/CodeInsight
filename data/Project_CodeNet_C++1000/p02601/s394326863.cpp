#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <stack>
#include <string>
#include <vector>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
 
int main()
{
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    int cnt = 0;
    while (a >= b)
    {
        b *= 2;
        cnt++;
    }
    while (b >= c)
    {
        c *= 2;
        cnt++;
    }
    if (cnt <= k)
    {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    
}