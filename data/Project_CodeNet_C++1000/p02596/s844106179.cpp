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
    int  k;
    cin >> k;
    long long  seven=0;
    int r=7;
    for (int i = 0; i < k ;i++)
    {
        if (r%k==0)
        {
            cout << i+1 << endl;
            return  0;
        }
        else
        {
            r*=10;
            r+=7;
            r%=k;
        }
        
    }
    cout << -1 << endl;
}
