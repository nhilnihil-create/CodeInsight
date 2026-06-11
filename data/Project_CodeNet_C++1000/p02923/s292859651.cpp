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


int main(void){
    int n;
    cin >> n;

    vector<int> h(n);
    int count=0;
    int max=0;

    cin >> h.at(0);
    for (int i = 1; i < n; i++)
    {
        cin >> h.at(i);
        if (h.at(i-1)>=h.at(i))
        {
            count++;
        }
        else if (count > max)
        {
            max = count;
            count = 0;
        }
        else
        {
            count=0;
        }


    }
    if (count>max)
    {
        max=count;
    }
    
    cout << max << endl;
}
