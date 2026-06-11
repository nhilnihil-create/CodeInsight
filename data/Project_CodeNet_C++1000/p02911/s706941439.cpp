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
    int n,k,q;
    cin >> n >> k >> q;

    vector<int> ans_num(n);
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        ans_num.at(a-1)++;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (k-(q-ans_num.at(i))>0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        
    }
    
    
}
