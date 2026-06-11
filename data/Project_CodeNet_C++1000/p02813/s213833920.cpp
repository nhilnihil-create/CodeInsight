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

    vector<int> p(n),q(n),r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p.at(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> q.at(i);
    }
    for (int i = 0; i < n; i++)
    {
        r.at(i)=i+1;
    }
    
    int count=1,a,b;
    do
    {
        if (p==r)
        {
            a=count;
        }
        if (q==r)
        {
            b=count;
        }
        count++;
    } while (next_permutation(r.begin(),r.end()));
    
    cout << abs(a-b) << endl;
}
