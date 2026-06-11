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
    int x;
    cin >> x;
    for (int i = 0; i < 8; i++)
    {
        if (x >= (i+2)*200 && x <= (i+3)*200-1)
        {
            cout << 8-i << endl;
            return 0;
        }
        
    }
    
}