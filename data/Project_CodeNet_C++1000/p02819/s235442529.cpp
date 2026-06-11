#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <functional>
#define _LIBCPP_DEBUG 0
using namespace std;

int main(void){
    int x;
    cin >> x;
    for (int i = x;; i++)
    {   
        int j;
        for (j = 2; j <= x; j++)
        {
            if (i%j==0)
            {   
                if (i==j)
                {
                    j=x+1;
                }
                break;
            }
        }
        if (j==x+1)
        {
            cout << i << endl;
            return 0;
        }
        
        
    }
}
