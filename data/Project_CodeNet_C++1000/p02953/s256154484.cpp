#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <tuple>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <functional>
#define _LIBCPP_DEBUG 0
using namespace std;
using ll = long long;

int main(void)
{
    int n;
    cin >> n;
    
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }
    
    for (int  i = 0; i < n-1; i++)
    {
        if (a.at(i + 1) - a.at(i) >0)
        {
            a.at(i + 1)--;
        }

        if (a.at(i)>a.at(i+1))
        {
            cout << "No" << endl;
            return 0;
        }
        
    }
    
    cout << "Yes" << endl;
}
