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
    int n;
    cin >> n;
    char prev,next;
    cin >> prev;
    int count=1;
    for (int  i = 1; i < n; i++)
    {
        cin >> next;
        if (prev!=next)
        {
            count++;
        }
        prev=next;
    }
    cout << count << endl;
}
