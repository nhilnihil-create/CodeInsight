#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (i*j == n)
            {
                cout << "Yes" << endl;
                return 0;
            }
            
        }
        
    }
    cout << "No" << endl;
}
    