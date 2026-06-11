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

#define MAX 1000000000000000000

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
        if(a.at(i)==0){
            cout << 0 << endl;
            return 0;
        }
    }
    
    long long answer=1;
    for (int i = 0; i < n; i++)
    {
        if (a.at(i)<=MAX/answer)
        {
            answer*=a.at(i);
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << answer << endl;
    
}
