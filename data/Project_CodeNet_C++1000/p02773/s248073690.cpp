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
    map<string, int> memo;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        memo[s]++;
    }

    int max=0;
    for (auto it = memo.begin(); it!=memo.end() ; it++)
    {
        if (it->second > max)
        {
            max=it->second;
        }
    }

    for (auto it = memo.begin(); it!=memo.end(); it++)
    {
        if (it->second==max)
        {
            cout << it->first << endl;
        }
        
    }
    
}
