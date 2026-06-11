#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>
#include <cstdio>
#include <cassert>
#include <functional>
#define _LIBCPP_DEBUG 0
using namespace std;

int main(void){
    int n;
    cin >> n;

    int minimum=200001,count=0;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        if (p<=minimum)
        {
            minimum=p;
            count++;
        }
    }
    cout << count << endl;
}
