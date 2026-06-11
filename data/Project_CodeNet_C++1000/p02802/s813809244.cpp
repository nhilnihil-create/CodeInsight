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
    int n,m;
    cin >> n >> m;

    int ac_num=0,wa_num=0;
    vector<int> judge(n);
    vector<int> wa(n);
    

    for (int i = 0; i < m; i++)
    {
        int p;
        string s;

        cin >> p >> s;
        
        if (judge.at(p-1)==1)
        {
            continue;
        }
        else if (s=="AC")
        {
            ac_num++;
            judge.at(p-1)++;
            wa_num+=wa.at(p-1);
        }
        else if (s=="WA")
        {
            wa.at(p-1)++;
        }
    }
    cout << ac_num << " "<< wa_num << endl;
}
