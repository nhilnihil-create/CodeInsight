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
    
    vector<int> a(n+1),b(n);
    for (int i = 0; i < n+1; i++)
    {
        cin >> a.at(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b.at(i);
    }
    
    ll count=0;
    for (int i = 0; i < n; i++)
    {
        if (b.at(i)<=a.at(i))
        {
            count+=b.at(i);
        }
        else if (b.at(i)<=a.at(i)+a.at(i+1))
        {
            count+=b.at(i);
            if (b.at(i)>a.at(i))
            {
                a.at(i+1) -= b.at(i) - a.at(i);
            }
        }
        else if (b.at(i)>a.at(i)+a.at(i+1))
        {
            count+=a.at(i)+a.at(i+1);
            a.at(i+1)=0;
        }
    }
    cout << count << endl;
}
